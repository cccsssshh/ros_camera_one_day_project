import rclpy as rp
from rclpy.node import Node
from sensor_msgs.msg import Image
from rclpy.qos import QoSProfile
from cv_bridge import CvBridge
import cv2
from capture_msgs.srv import Capture

import datetime

class Capture_server(Node):

    def __init__(self):
        super().__init__("camera_service")
        self.cv_bridge = CvBridge()
        self.qos = QoSProfile(depth=10)
        self.capture_service = self.create_service(Capture, 'camera_service', self.service_callback)
        self.sub_image = None
        self.video_writer = None
        self.is_recording = False

        self.declare_parameter("file_directory", '')
        self.declare_parameter("frame_rate" , 20)
        self.declare_parameter("width" , 640)
        self.declare_parameter("height" , 480)

        self.file_dir = self.get_parameter("file_directory").value
        self.frame_rate = self.get_parameter("frame_rate").value
        self.width = self.get_parameter("width").value
        self.height = self.get_parameter("height").value

        self.get_logger().info(f"saving directory is {self.file_dir}")
        self.get_logger().info(f"frame_rate : {self.frame_rate}")
        self.get_logger().info(f"width : {self.width}")
        self.get_logger().info(f"height : {self.height}")


    def service_callback(self, request, response):
        action_type = request.action
        filter_type = request.filter_type
        if self.sub_image is None:
            self.get_logger().info('Service called, starting to subscribe to topic...')
            if self.check_topic_existence('/'+ filter_type) == True:
                response.message = "Subscription started with filter: " + filter_type
                if action_type == "capture":
                    self.sub_image = self.create_subscription(
                        Image,
                        '/'+ filter_type,
                        self.capture_callback,
                        self.qos)
                elif action_type == "recording start":
                    response.message = "Subscription started with filter: " + filter_type
                    self.now = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
                    self.sub_image = self.create_subscription(
                        Image,
                        '/'+ filter_type,
                        self.recording_start,
                        self.qos)
                elif action_type == "recording stop":
                    self.get_logger().info('is not recording now')
                    response.message = 'is not recording now'
        else:
            if self.is_recording == True:
                if action_type == "recording stop":
                    self.recording_stop()
                    response.message = "Recording is done."

        response.success = True

        return response
    
    def recording_start(self, msg):
        self.get_logger().info(f'Recording is started', once = True)
        filename = self.file_dir + 'video_'+ self.now + ".avi"
        img = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        
        if self.is_recording == False:
            fourcc = cv2.VideoWriter_fourcc(*'DIVX')
            self.video_writer = cv2.VideoWriter(filename, fourcc, self.frame_rate, (self.width, self.height))
            self.is_recording = True

        self.record_frame(msg)

    def record_frame(self, msg):
        if self.is_recording and self.video_writer:
            img = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            self.video_writer.write(img)

    def recording_stop(self):
        if self.sub_image is not None:
            self.destroy_subscription(self.sub_image)
            self.sub_image = None
            self.is_recording = False
            self.video_writer.release()
            self.video_writer = None
            self.get_logger().info('Recording is done.')

    def capture_callback(self, msg):
        self.get_logger().info(f'Capture is started')
        img = self.cv_bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        now = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = self.file_dir + 'capture_'+ now + ".png"
        cv2.imwrite(filename, img)

        if self.sub_image is not None:
            self.destroy_subscription(self.sub_image)
            self.sub_image = None
            self.get_logger().info('Capture is done.')
        
    def check_topic_existence(self, topic_name):
        topics = self.get_topic_names_and_types()

        for name, types in topics:
            if name == topic_name:
                self.get_logger().info(f"Topic '{topic_name}' exists with types {types}.")
                return True
        self.get_logger().info(f"Topic '{topic_name}' does not exist.")
        return False


def main(args = None):
    rp.init(args= args)
    node = Capture_server()
    try:
        rp.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Stopped by Keyboard')
    finally:
        node.destroy_node()
        rp.shutdown()


if __name__ == "__main__":
    main()
