import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('ros_package_template'), 'config', 'default.yaml')

    template_node = Node(
        name='template_node',
        package='ros_package_template',
        executable='ros_package_template_node',
        namespace='',
        output='screen',
        parameters=[config],
        ## Uncomment this line to change log level to DEBUG
        # arguments=['--ros-args', '--log-level', 'DEBUG'],
    )

    return LaunchDescription([template_node])
