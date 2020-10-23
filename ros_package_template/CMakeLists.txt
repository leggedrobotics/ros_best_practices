cmake_minimum_required(VERSION 3.10)
project(ros_package_template)

## Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## By adding -Wall and -Werror, the compiler does not ignore warnings anymore,
## enforcing cleaner code.
add_definitions(-Wall -Werror)

## Find catkin macros and libraries
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

## Find system libraries
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  # Set manually because Eigen sets a non standard INCLUDE DIR
  ${EIGEN3_INCLUDE_DIR}
  # Set because Boost is an internal dependency, not transitive.
  ${Boost_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(${PROJECT_NAME}_core
   src/Algorithm.cpp
)
target_compile_features(${PROJECT_NAME}_core INTERFACE cxx_std_14)

## Declare cpp executables
add_executable(${PROJECT_NAME}
  src/${PROJECT_NAME}_node.cpp
  src/RosPackageTemplate.cpp
)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_14)
ament_target_dependencies(${PROJECT_NAME} rclcpp sensor_msgs)

#############
## Install ##
#############

# Mark executables and/or libraries for installation
install(
  TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_core
  DESTINATION lib/${PROJECT_NAME}
)

#############
## Testing ##
#############

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
