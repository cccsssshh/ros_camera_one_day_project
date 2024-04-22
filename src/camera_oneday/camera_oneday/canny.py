import rclpy as rp # ROS2의 Python 라이브러리, 주로 Node를 구현, 관리
from rclpy.node import Node # rclpy 패키지의 Node 클래스 import
from sensor_msgs.msg import Image # sensor_msgs 패키지에서 Image 메세지 타입 import, ROS2에서 이미지를 주고 받을 때 사용되는 메세지 형식
from rclpy.qos import QoSProfile # ROS2에서 통신 품질을 관리하는 클래스(Quality of Service)

import numpy as np # "Numeric Python"의 약자이며 대규모 다차원 배열과 행렬 연산에 필요한 다양한 함수와 메소드를 제공, Numpy의 가장 큰 특징은 다차원 배열 객체인 ndarray를 제공

import cv2 # Opencv 라이브러리를 cv2라는 이름으로 import, 컴퓨터 비전 프로젝트에 필요한 다양한 기능을 제공
from cv_bridge import CvBridge # ROS2 이미지 메세지와 openCV 이미지 포멧 간의 변환을 도와주는 라이브러리 중 CvBridge를 import


class ImgSubscriber(Node): # ImgSubcriber 클래스 선언, rclpy의 node 클래스를 부모로 함

    def __init__(self): # 초기 선언
        super().__init__("canny") # 노드의 이름을 canny로 함
        self.cv_bridge = CvBridge() # CvBridge() 객체 생성
        self.qos = QoSProfile(depth=10) # QosProfile 객체 생성, depth : 퍼블리셔가 유지할 메시지 수, 최근 10개 메시지만 유지하겠다.
        self.declare_parameter("thrs1", 2000) # threshold1의 값 선언, 하이스테리시스가 작동하기 시작하는 최소 임계값
        self.declare_parameter("thrs2", 4000) # threshold2의 값 선언, 하이스테리시스가 작동을 멈추는 최대 임계값

        # 일반적으로 임계값은 2배 차이
        self.thrs1 = self.get_parameter("thrs1").value # 선언된 threshold1의 값 param/filter.yaml에서 가져오기
        self.thrs2 = self.get_parameter("thrs2").value # 선언된 threshold2의 값 param/filter.yaml에서 가져오기
        
        self.get_logger().info(f"Parameter thrs1: {self.thrs1}") # threshol1 값 로깅
        self.get_logger().info(f"Parameter thrs2: {self.thrs2}") # threshol2 값 로깅

        # ROS 2 노드에 메시지 서브스크립션을 생성
        self.subscription = self.create_subscription(
            Image, # 메세지 타입
            "/camera", # 이미지 토픽
            self.listener_callback, # subciption의 콜백 함수
            self.qos # 보관할 메세지 수 10개
            )
        self.subscription  # prevent unused variable warning

        self.canny_publisher = self.create_publisher(Image, '/canny_edge', self.qos) # canny_edge 이미지 메세지 발행자 생성 

    def listener_callback(self, msg): # 구독자가 토픽을 받았을 때 호출되는 콜백함수
        img = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8') # ROS 이미지 메시지를 OpenCV 이미지(numpy.ndarray)로 변환. 'bgr8'는 색상 인코딩 형식

        canny_img = self.canny(img) # 이미지를 canny_edge로 변환
        pub_img = self.cv_bridge.cv2_to_imgmsg(canny_img, "mono8") # OpenCV 이미지(numpy.ndarray)를 ROS 이미지 메시지로 변환. 'mono8'는 색상 인코딩 형식
        self.canny_publisher.publish(pub_img) # canny 이미지 토픽 발행

    def canny(self, img): # rgb 이미지를 canny 이미지로 변환하는 매서드
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) # rgb를 gary로 변환
        edge = cv2.Canny(gray, self.thrs1, self.thrs2, apertureSize= 5) # 그레이 이미지를 canny_edge로 변환
        
        return edge # canny_edge 반환

def main(args = None):
    rp.init(args= args) # rclpy 초기화, ros2 시스템과의 통신을 시작하기 전 필수 호출

    img_subscriber = ImgSubscriber() # ImgSubcriber 클래스 인스턴스 생성
    try: # rp.spin()을 블로킹 모드로 실행
        rp.spin(img_subscriber) # node에 대해 무한 루프, 프로그램이 종료될 때까지 블로킹 상태로 유지
    except KeyboardInterrupt: # 키보드 인터럽트 (Ctrl + C)로 중단 됐을 때 실행
        img_subscriber.get_logger().info('Stopped by Keyboard') # Ctrl + C로 중단되었을 때 로깅
    finally: #프로그램 종료시 실행
        img_subscriber.destroy_node() # 노드의 리소스를 정리하고 종료, 노드와 관련된 ROS 핸들을 정리
        rp.shutdown() # rclpy 라이브러리 종료, ROS2와의 모든 연결 종료, 리소스 해제


if __name__ == "__main__":
    main()