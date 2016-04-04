#include "/home/olmo/jade_workspace/src/using_marker_array_simple/include/mas_sphere_oo.h"

MAS_OO::MAS_OO(ros::NodeHandle *nh){
    n=nh;
    marker_pub = n->advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 1000);
    sub_r = n->subscribe("set_pos_c_r", 1000, &MAS_OO::positionCallbackRed, this);
    sub_g = n->subscribe("set_pos_c_g", 1000, &MAS_OO::positionCallbackGreen, this);
    sub_b = n->subscribe("set_pos_c_b", 1000, &MAS_OO::positionCallbackBlue, this);
    initialize_stuff();
}

void MAS_OO::initialize_stuff(){
//    visualization_msgs::Marker a;
//    marker_array_msg.markers.push_back(a);
    marker_array_msg.markers.resize(6);//final->width * final->height);
       for( int i = 0; i < 6; i++){
            marker_array_msg.markers[i].header.frame_id = "/my_frame";
            marker_array_msg.markers[i].header.stamp = ros::Time();
            marker_array_msg.markers[i].ns = "array_simple";
            marker_array_msg.markers[i].id = i;
            marker_array_msg.markers[i].type = visualization_msgs::Marker::SPHERE;
            marker_array_msg.markers[i].action = visualization_msgs::Marker::ADD;
            marker_array_msg.markers[i].pose.position.x = 0.0;
            marker_array_msg.markers[i].pose.position.y = 0.0;
            marker_array_msg.markers[i].pose.position.z = 0.0;
            marker_array_msg.markers[i].pose.orientation.x = 0.0;
            marker_array_msg.markers[i].pose.orientation.y = 0.0;
            marker_array_msg.markers[i].pose.orientation.z = 0.0;
            marker_array_msg.markers[i].pose.orientation.w = 1.0;
            marker_array_msg.markers[i].scale.x = 1.0;
            marker_array_msg.markers[i].scale.y = 1.0;
            marker_array_msg.markers[i].scale.z = 1.0;
            marker_array_msg.markers[i].color.a = 1.0;
            if(i == 0){
                marker_array_msg.markers[i].color.r = 1.0;
                marker_array_msg.markers[i].color.g = 0.0;
                marker_array_msg.markers[i].color.b = 0.0;
            }
            if(i == 1){
                marker_array_msg.markers[i].color.r = 0.0;
                marker_array_msg.markers[i].color.g = 1.0;
                marker_array_msg.markers[i].color.b = 0.0;
            }
            if(i == 2){
                marker_array_msg.markers[i].color.r = 0.0;
                marker_array_msg.markers[i].color.g = 0.0;
                marker_array_msg.markers[i].color.b = 1.0;
            }
            if(i == 3){
                marker_array_msg.markers[i].color.r = 0.8;
                marker_array_msg.markers[i].color.g = 0.8;
                marker_array_msg.markers[i].color.b = 0.0;
            }
            if(i == 4){
                marker_array_msg.markers[i].color.r = 1.0;
                marker_array_msg.markers[i].color.g = 0.2;
                marker_array_msg.markers[i].color.b = 0.2;
            }
            if(i == 5){
                marker_array_msg.markers[i].color.r = 0.2;
                marker_array_msg.markers[i].color.g = 1.0;
                marker_array_msg.markers[i].color.b = 1.0;
            }
       }
       marker_pub.publish(marker_array_msg);
}

bool MAS_OO::run(){
    ros::Rate r(30);
    while (marker_pub.getNumSubscribers() < 1)
    {
        ROS_WARN_ONCE("Please create a subscriber to the marker_array");
        sleep(1);
    }
    while (ros::ok())
    {
        ros::spinOnce();
        marker_pub.publish(marker_array_msg);
        r.sleep();
    }
}

void MAS_OO::positionCallbackRed(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
    pose=*msg;
    marker_array_msg.markers[0].pose.position.x=pose.pose.position.x;
    marker_array_msg.markers[3].pose.position.x=-(pose.pose.position.x);
    ROS_INFO("I heard R[%f]:", pose.pose.position.x);
    //marker.pose=msg->pose;
}

void MAS_OO::positionCallbackGreen(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
    pose=*msg;
    marker_array_msg.markers[1].pose.position.y=pose.pose.position.y;
    marker_array_msg.markers[4].pose.position.y=-(pose.pose.position.y);
    ROS_INFO("I heard G[%f]:", pose.pose.position.y);
    //marker.pose=msg->pose;
}

void MAS_OO::positionCallbackBlue(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
    pose=*msg;
    marker_array_msg.markers[2].pose.position.z=pose.pose.position.y;
    marker_array_msg.markers[5].pose.position.z=-(pose.pose.position.y);
    ROS_INFO("I heard B[%f]:", pose.pose.position.y);
    //marker.pose=msg->pose;
}
int main( int argc, char** argv )
{
    ros::init(argc, argv, "marker_array_sphere");
    ros::NodeHandle n;
    MAS_OO instance(&n);
    instance.run();
}
