#include "ros_package_template/RosPackageTemplate.hpp"

// STD
#include <string>

namespace ros_package_template {

RosPackageTemplate::RosPackageTemplate(const std::string& name)
    : Node(name)
{
}

RosPackageTemplate::~RosPackageTemplate() = default;

} /* namespace */
