#pragma once

#include "ros_package_template/algorithm.hpp"

// ROS2
#include "rclcpp/rclcpp.hpp"

namespace ros_package_template
{

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
  RosPackageTemplate(const rclcpp::NodeOptions & options);

    /*!
   * Destructor.
   */
    virtual ~RosPackageTemplate();
};

}  // namespace ros_package_template
