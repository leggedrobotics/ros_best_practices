#include <ros/ros.h>
#include "ros_package_template/RosPackageTemplate.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ros_package_template");
  ros::NodeHandle nodeHandle("~");

  ros_package_template::RosPackageTemplate rosPackageTemplate(nodeHandle);

  ros::spin();
  return 0;
}
