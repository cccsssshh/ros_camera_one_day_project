import rclpy as rp
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class ImgPublisher(Node):
    def __init__(self):
        super().__init__("img_publisher")
        self.publisher = self.create_publisher(
            Image,
            "/camera",
            10
        )
        time_period = 0.01
        self.timer = self.create_timer(time_period, self.time_callback)
        self.cap = cv2.VideoCapture(0)
        self.cv_bridge = CvBridge()

        self.declare_parameter("width", 640)
        self.declare_parameter("length", 480)

        self.width = self.get_parameter("width").value
        self.length = self.get_parameter("length").value
        
        output_msg = "Video width : " + str(self.width) + "\n\r"
        output_msg = output_msg + "Video Length : " + str(self.length)
        self.get_logger().info(output_msg)

    def time_callback(self):
        ref, frame = self.cap.read()
        frame = cv2.resize(frame, (self.width, self.length))
        img = self.cv_bridge.cv2_to_imgmsg(frame, "bgr8")
        self.get_logger().info(f"msg type : {type(img)}", once=True)
        self.publisher.publish(img)
        cv2.waitKey(1)

def main():
    rp.init()
    node = ImgPublisher()
    rp.spin(node)
    node.destroy_node()
    rp.shutdown()

if __name__ == "__main__":
    main()