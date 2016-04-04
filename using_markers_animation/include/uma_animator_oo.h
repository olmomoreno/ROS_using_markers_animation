#ifndef __UMA_ANIMATOR_OO_H__
#define __UMA_ANIMATOR_OO_H__

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseStamped.h>

class BSR_OO{
public:    
    BSR_OO(ros::NodeHandle*);
    bool run();
protected:
    ros::NodeHandle *n;
    ros::Publisher c_r_pub;
    ros::Publisher c_g_pub;
    ros::Publisher c_b_pub;
    visualization_msgs::Marker marker;
    geometry_msgs::PoseStamped pose;
    void initialize_stuff();
};
#endif
