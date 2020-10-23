#pragma once

#include "ros_package_template/Algorithm.hpp"

// ROS2
#include "rclcpp/rclcpp.hpp"

namespace ros_package_template {

/*!
 * Main class for the node to handle the ROS interfacing.
 */
class RosPackageTemplate : public rclcpp::Node
{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  RosPackageTemplate(const std::string& name);

  /*!
   * Destructor.
   */
  virtual ~RosPackageTemplate();
};

} /* namespace */
