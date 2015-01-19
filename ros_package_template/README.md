# Package Name

## Overview

This is a template: replace, remove, and add where required. Describe here what this package does and what it's meant for in a few sentences.

The PACKAGE NAME package has been tested under [ROS] Indigo and Ubuntu 14.04. This is research code, expect that it changes often and any fitness for a particular purpose is disclaimed.

The source code is released under a [BSD 3-Clause license](ros_package_template/LICENSE).

**Author: Name of authors   
Contact: Name of person to contact, email@ethz.ch  
Affiliation: Autonomous Systems Lab, ETH Zurich**

![Example image](doc/example.jpg)


### Publications

If you use this work in an academic context, please cite the following publication(s):
	
* P. Fankhauser, M. Bloesch, C. Gehring, M. Hutter, and R. Siegwart: **PAPER TITLE**. IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS), 2015. ([PDF](http://dx.doi.org/10.3929/ethz-a-010173654))


## Installation

### Dependencies

- [Robot Operating System (ROS)](http://wiki.ros.org) (middleware for robotics),
- [Eigen](http://eigen.tuxfamily.org) (linear algebra library),
- [kindr](http://github.com/ethz-asl/kindr) (kinematics and dynamics library for robotics),
- [Point Cloud Library (PCL)](http://pointclouds.org/) (point cloud processing),
- [Grid Map](https://github.com/ethz-asl/grid_map) (grid map library for mobile robots),
- [starleth_ros_common](http://bitbucket.org/ethz-asl-lr/c_starleth_ros_common) (common [ROS] packages for StarlETH robot).
- [Gazebo](http://gazebosim.org/) (robot simulator)

		sudo apt-get install ros-indigo-gazebo-ros-pkgs

	More information on the installation of [Gazebo] for [ROS] is given [here](http://gazebosim.org/tutorials?tut=ros_installing&cat=connect_ros),
- [Schweizer-Messer](http://github.com/ethz-asl/Schweizer-Messer) (programming tools for robotics),
	
		sudo add-apt-repository ppa:ethz-asl/common
		sudo apt-get update
		sudo apt-get install schweizer-messer-common-dev schweizer-messer-timing-dev


### Building

In order to install, clone the latest version from this repository into your catkin workspace and compile the package using

	cd catkin_workspace/src
	git clone https://github.com/ethz-asl/PACKAGE_NAME.git
	cd ../
	catkin_make


### Unit Tests

Run the unit tests with

	catkin_make run_tests_PACKAGE_NAME run_tests_PACKAGE_NAME


## Usage

Describe the quickest way to run this software, for example:

Load and publish a .ply file with

	rosrun ply_publisher ply_publisher _file_path:=/home/user/your_point_cloud.ply _topic:=/point_cloud _frame:=/sensor_frame

Optionally, you can also add `_rate:=1.0` to have the node publish your point cloud at the specified rate. To create your own launch-file, you can use the example from `ply_publisher/launch/example.launch`.


## Nodes

### NODE_A_NAME

Write a description of the NODE_A_NAME node.


#### Subscribed Topics

* **`actuators`** ([starleth_msgs/SeActuatorCommands])

	The actuator commands for the ...
	
* **`grid_map`** ([grid_map_msg/GridMap])

	The elevation map as grid map.


#### Published Topics

* **`point_cloud`** ([sensor_msgs/PointCloud2])

	The resulting point cloud.
	
* **`occupancy_grid`** ([nav_msgs/OccupancyGrid])
	
	The estimated traversability as occupancy grid.

* **`marker`** ([visualization_msgs/Marker])

	The marker for visualization in [rviz].


#### Services

* **`trigger`** ([std_srvs/Empty])

	Trigger the computation process. For example, you can trigger the computation from the console with

		rosservice call /NODE_A_NAME/trigger


#### Parameters

* **`input_topic`** (string, default: "/my_topic")

	The name of the input topic.
	
* **`cache_size`** (int, default: 200, min: 0, max: 1000)
	
	The size of the cache.

* **`map/length`** (double, default: 3.0)

	The length of the map (in \[m\]).

* **`map/resolution`** (double, default: 0.003, min: 0.01)
	
	The resolution of the map (in \[m\] per cell).


### NODE_B_NAME

...


## Bugs & Feature Requests

Please report bugs and request features using the [Issue Tracker](https://github.com/ethz-asl/ros_best_practices/issues).


[ROS]: http://www.ros.org
[rviz]: http://wiki.ros.org/rviz
[Eigen]: http://eigen.tuxfamily.org
[Gazebo]: http://gazebosim.org/
[rviz]: http://wiki.ros.org/rviz
[starleth_msgs/SeActuatorCommands]: https://bitbucket.org/ethz-asl-lr/c_starleth_ros_common/raw/master/starleth_msgs/msg/SeActuatorCommands.msg
[grid_map_msg/GridMap]: https://github.com/ethz-asl/grid_map/blob/master/grid_map_msg/msg/GridMap.msg
[sensor_msgs/PointCloud2]: http://docs.ros.org/api/sensor_msgs/html/msg/PointCloud2.html
[visualization_msgs/Marker]: http://docs.ros.org/api/visualization_msgs/html/msg/Marker.html
[nav_msgs/OccupancyGrid]: http://docs.ros.org/api/nav_msgs/html/msg/OccupancyGrid.html
[std_srvs/Empty]: http://docs.ros.org/api/std_srvs/html/srv/Empty.html