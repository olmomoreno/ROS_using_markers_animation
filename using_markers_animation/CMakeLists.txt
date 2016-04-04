# What version of CMake is needed?
cmake_minimum_required(VERSION 2.8.3)

# The name of this package.
project(using_markers_animation)

# Find the catkin build system, and any other packages on which we depend.
find_package(catkin REQUIRED COMPONENTS roscpp rospy visualization_msgs)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

# Declare our catkin package.
catkin_package()

# Specify locations of header files.
include_directories(include ${catkin_INCLUDE_DIRS})

# uma_cube_red.cpp
add_executable(marker_cube_red_exe src/uma_cube_red.cpp)
target_link_libraries(marker_cube_red_exe ${catkin_LIBRARIES})

# uma_cube_green.cpp
add_executable(marker_cube_green_exe src/uma_cube_green.cpp)
target_link_libraries(marker_cube_green_exe ${catkin_LIBRARIES})

# uma_cube_blue.cpp
add_executable(marker_cube_blue_exe src/uma_cube_blue.cpp)
target_link_libraries(marker_cube_blue_exe ${catkin_LIBRARIES})

# uma_animator.cpp
add_executable(uma_animator_exe src/uma_animator.cpp)
target_link_libraries(uma_animator_exe ${catkin_LIBRARIES})
