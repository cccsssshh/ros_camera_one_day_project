import os

from ament_index_python import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description(): 
    size_dir = LaunchConfiguration(
        'param_dir',
        default=os.path.join(
        get_package_share_directory('camera_oneday'),
        'param',
        'size.yaml')
        )
    saving_dir = LaunchConfiguration(
        'param_dir',
        default=os.path.join(
        get_package_share_directory('camera_oneday'),
        'param',
        'saving.yaml')
        )
    
    return LaunchDescription(
        [
            Node(
                package='camera_oneday',
                executable='camera_server',
                name='camera_server',
                parameters=[size_dir, saving_dir],
                output='screen'),
        ]
    )