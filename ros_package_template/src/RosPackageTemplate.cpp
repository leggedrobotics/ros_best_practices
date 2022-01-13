#include "ros_package_template/RosPackageTemplate.hpp"

// STD
#include <string>

namespace ros_package_template
{

RosPackageTemplate::RosPackageTemplate(const rclcpp::NodeOptions & options)
: Node("RosPackageTemplateNode", options)
{
  RCLCPP_INFO(this->get_logger(), "Starting RosPackageTemplateNode!");
}

RosPackageTemplate::~RosPackageTemplate() = default;

}  // namespace ros_package_template

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(ros_package_template::RosPackageTemplate)