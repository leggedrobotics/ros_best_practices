#include "rclcpp/rclcpp.hpp"

#include "ros_package_template/RosPackageTemplate.hpp"

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  auto node = std::make_shared<ros_package_template::RosPackageTemplate>("ros_package_template");

  exec.add_node(node);
  exec.spin();
  rclcpp::shutdown();
  return 0;
}
