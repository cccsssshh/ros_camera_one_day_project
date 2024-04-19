import rclpy as rp
from rclpy.node import Node
from rclpy.qos import QoSProfile
from sensor_msgs.msg import Image
import numpy as np
import cv2
from cv_bridge import CvBridge


class ImgSubscriber(Node):

    def __init__(self):
        super().__init__("canny")
        self.cv_bridge = CvBridge()
        qos = QoSProfile(depth=10)
        self.declare_parameter("thrs1", 2000)
        self.declare_parameter("thrs2", 4000)

        self.thrs1 = self.get_parameter("thrs1").value
        self.thrs2 = self.get_parameter("thrs2").value
        
        self.get_logger().info(f"Parameter thrs1: {self.thrs1}")
        self.get_logger().info(f"Parameter thrs2: {self.thrs2}")


        self.subscription = self.create_subscription(
            Image,
            "/camera", # 이미지 토픽
            self.listener_callback,
            qos
            )
        self.subscription  # prevent unused variable warning

        self.canny_publisher = self.create_publisher(Image, '/canny_edge', qos)

    def listener_callback(self, msg):
        img = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        canny_img = self.canny(img)
        pub_img = self.cv_bridge.cv2_to_imgmsg(canny_img, "mono8")
        self.canny_publisher.publish(pub_img)

    def canny(self, img):
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        edge = cv2.Canny(gray, self.thrs1, self.thrs2, apertureSize= 5)
        
        return edge

def main(args = None):
    rp.init(args= args)

    img_subscriber = ImgSubscriber()
    try:
        rp.spin(img_subscriber)
    except KeyboardInterrupt:
        img_subscriber.get_logger().info('Stopped by Keyboard')
    finally:
        img_subscriber.destroy_node()
        rp.shutdown()


if __name__ == "__main__":
    main()