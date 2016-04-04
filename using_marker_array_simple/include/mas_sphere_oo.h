#ifndef __MAS_SPHERE_OO_H__
#define __MAS_SPHERE_OO_H__

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <geometry_msgs/PoseStamped.h>

class MAS_OO{
public:    
    MAS_OO(ros::NodeHandle*);
    bool run();
protected:
    ros::NodeHandle *n;
    ros::Publisher marker_pub;
    ros::Subscriber sub_r;
    ros::Subscriber sub_g;
    ros::Subscriber sub_b;
    visualization_msgs::MarkerArray marker_array_msg;
    void positionCallbackRed(const geometry_msgs::PoseStamped::ConstPtr &msg);
    void positionCallbackGreen(const geometry_msgs::PoseStamped::ConstPtr &msg);
    void positionCallbackBlue(const geometry_msgs::PoseStamped::ConstPtr &msg);
    geometry_msgs::PoseStamped pose;
    void initialize_stuff();
};
#endif
