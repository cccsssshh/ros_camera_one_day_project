import rclpy as rp # ROS2의 Python 라이브러리, 주로 Node를 구현, 관리
from rclpy.node import Node # rclpy 패키지의 Node 클래스 import
from sensor_msgs.msg import Image # sensor_msgs 패키지에서 Image 메세지 타입 import, ROS2에서 이미지를 주고 받을 때 사용되는 메세지 형식
from cv_bridge import CvBridge # ROS2 이미지 메세지와 openCV 이미지 포멧 간의 변환을 도와주는 라이브러리 중 CvBridge를 import
import cv2 # Opencv 라이브러리를 cv2라는 이름으로 import, 컴퓨터 비전 프로젝트에 필요한 다양한 기능을 제공

class ImgPublisher(Node): # Imgpublisher 클래스 선언, rclpy의 node 클래스를 부모로 함
    def __init__(self): # 초기 선언
        super().__init__("img_publisher") # 노드 이름 선언
        self.publisher = self.create_publisher(
            Image, # 메세지 타입
            "/camera", # 토픽, String형태
            10 # qos_profile, int형태
        ) # callback_group, event_callback이 parameter도 선택적으로 들어갈 수 있음
        time_period = 0.01 # timer의 시간 초 정의
        self.timer = self.create_timer(time_period, self.time_callback) # 매 time_period(초)마다 콜백함수(self.time_callback)함수가 호출 된다.
        self.cap = cv2.VideoCapture(0) # opencv의 VideoCapture 클래스의 인스턴스를 생성, 0 : 시스템에 연결된 첫번째 카메라,  ** "정수 : 연결된 카메라 인덱스", "문자열 : 비디오 파일 경로, URL" ** + API Preference(특정 비디오 캡쳐 API)를 선택적으로 명시할 수 있다.
        if not self.cap.isOpened(): # 클래스 인스턴스가 올바르게 초기화되었는지 확인
            self.get_logger().info("Camera open failed!") # 클래스 인스턴스가 생성되지 않았다는 로그를 남김

        self.cv_bridge = CvBridge() #CVBridge() 클래스의 인스턴스 생성

        self.declare_parameter("width", 640) # width 파라미터 선언 & 초기화
        self.declare_parameter("length", 480) # length 파라미터 선언 & 초기화

        self.width = self.get_parameter("width").value # 노드에 선언된 'width' 파라미터의 값을 param 폴더의 size.yaml에서 가져오기
        self.length = self.get_parameter("length").value # 노드에 선언된 'length' 파라미터의 값을 param 폴더의 size.yaml에서 가져오기
        
        output_msg = "Video width : " + str(self.width) + "\n\r"
        output_msg = output_msg + "Video Length : " + str(self.length)
        self.get_logger().info(output_msg) # 영상의 width, length의 크기의 로그 남김

    def time_callback(self): # self.timer가 time_period마다 호출하는 callback 함수
        ref, frame = self.cap.read() # 연결된 비디오 소스에서 프레임 읽기 (ref, frame)형태로 ret : 프레임 읽기 성공 여부(boolean), frame : 읽은 프레임 이미지 데이터(), rgb : (rows, columns, 3), gray : (rows, columns)
        frame = cv2.resize(frame, (self.width, self.length)) # 읽은 프레임을 설정된 width와 length로 크기 조정
        img = self.cv_bridge.cv2_to_imgmsg(frame, "bgr8") # OpenCV 이미지(numpy.ndarray)를 ROS 이미지 메시지로 변환. 'bgr8'는 색상 인코딩 형식
        self.publisher.publish(img) # 변환된 이미지 메시지를 ROS 토픽으로 발행
        self.get_logger().info(f"msg type : {type(img)}", once=True) # 발행된 이미지 메시지의 타입 로깅, 로그는 한 번만 출력
        #cv2.waitKey(1) # cv2.waitkey(delay), delay : 키 입력을 기다리는 시간(ms 단위), delay = 0 이면 무한히 대기 - imshow가 없는데 이걸 왜 썼지?

def main():
    rp.init() # rclpy 초기화, ros2 시스템과의 통신을 시작하기 전 필수 호출
    node = ImgPublisher() # ImgPublisher 클래스 인스턴스 생성
    rp.spin(node) # node에 대해 무한 루프, 프로그램이 종료될 때까지 블로킹 상태로 유지
    node.destroy_node() # 노드의 리소스를 정리하고 종료, 노드와 관련된 ROS 핸들을 정리
    rp.shutdown() # rclpy 라이브러리 종료, ROS2와의 모든 연결 종료, 리소스 해제

if __name__ == "__main__":
    main()