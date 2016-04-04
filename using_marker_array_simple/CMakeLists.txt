# What version of CMake is needed?
cmake_minimum_required(VERSION 2.8.3)

# The name of this package.
project(using_marker_array_simple)

# Find the catkin build system, and any other packages on which we depend.
find_package(catkin REQUIRED COMPONENTS roscpp visualization_msgs)

# Declare our catkin package.
catkin_package()

# Specify locations of header files.
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(marker_array_sphere_exe src/mas_sphere.cpp)
target_link_libraries(marker_array_sphere_exe ${catkin_LIBRARIES})
