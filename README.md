# ros_camera_one_day_project

## Python Requirements
```
pip install opencv-python==4.9.0.80
pip install numpy==1.26.4
```
## ROS Requirements
```
sudo apt install ros-humble-cv-bridge=3.2.1
```


## Node
1. img_publisher
 - 카메라 프레임을 전송

2. canny
   - 카메라 프레임으로 부터 받은 이미지를 canny_edge로 변환
    
3. camera_server
  - 캡쳐
  - 녹화 시작
  - 녹화 종료
 

```
ros2 service call /camera_service capture_msgs/srv/Capture "{filter_type : <필터>, action : <행동>}"
```
필터 : camera, canny

행동 : capture, recording start, recording stop

Service call - X
![image](https://github.com/cccsssshh/ros_camera_one_day_project/assets/157219758/0b42e113-a3a5-49e3-bea4-ae625d599970)

Service call - O
![image](https://github.com/cccsssshh/ros_camera_one_day_project/assets/157219758/e0fef340-6df4-4b37-9136-7478e6417535)

## 실행 순서
1. ros2 launch camera_oneday camera.launch.py
2. ros2 launch camera_oneday canny.launch.py
3. ros2 launch camera_oneday camera_server.launch.py
4. ros2 service call /capture_service capture_msgs/srv/Capture "{filter_type : <필터>, action : <행동>}"
