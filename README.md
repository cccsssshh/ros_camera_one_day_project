# ros_camera_one_day_project

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
ros2 service call /camera_service capture_msgs/srv/Capture "{filter_type : camera, action : recording stop}"
```
필터 : camera, canny

행동 : capture, recording start, recording stop

Service call - X
![image](https://github.com/cccsssshh/ros_camera_one_day_project/assets/157219758/0b42e113-a3a5-49e3-bea4-ae625d599970)

Service call - O
![image](https://github.com/cccsssshh/ros_camera_one_day_project/assets/157219758/e0fef340-6df4-4b37-9136-7478e6417535)
