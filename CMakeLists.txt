cmake_minimum_required(VERSION 2.8.3)
project(goal_detection)

## Add support for C++11, supported in ROS Kinetic and newer
# add_definitions(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

FIND_PACKAGE(OpenCV REQUIRED)

#anders wilt em ni compileren
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -march=core-avx-i -O2") 


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES goal_detection
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

LIST(APPEND CMAKE_MODULE_PATH /usr/local/lib/cmake)

add_executable(goal_detection_node src/goal.cpp)

target_link_libraries(goal_detection_node 
  ${catkin_LIBRARIES} 
  ${OpenCV_LIBS}
)
