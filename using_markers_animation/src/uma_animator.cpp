#include "/home/olmo/jade_workspace/src/using_markers_animation/include/uma_animator_oo.h"

BSR_OO::BSR_OO(ros::NodeHandle *nh){
    n=nh;
    c_r_pub = n->advertise<geometry_msgs::PoseStamped>("set_pos_c_r", 1000);
    c_g_pub = n->advertise<geometry_msgs::PoseStamped>("set_pos_c_g", 1000);
    c_b_pub = n->advertise<geometry_msgs::PoseStamped>("set_pos_c_b", 1000);
    initialize_stuff();
}

void BSR_OO::initialize_stuff(){

}

bool BSR_OO::run(){
    ros::Rate r(100);
    while (ros::ok())
    {
        ros::spinOnce();
	float c_r_px;
	float c_r_py;
	float c_r_pz;
	float c_g_px;
	float c_g_py;
	float c_g_pz;
	float c_b_px;
	float c_b_py;
	float c_b_pz;
	int flag;

	if(flag==0){
		if(c_r_px >= 5.0){
			flag=1;
		}
		else{
			c_r_px = c_r_px + 0.05;
        		c_g_py = c_g_py + 0.05;
			c_b_pz = c_b_pz + 0.05;
		}
	}
	else{
		if(c_r_px <= 0.0){
			flag=0;
		}
		else{
			c_r_px = c_r_px - 0.05;
        		c_g_py = c_g_py - 0.05;
			c_b_pz = c_b_pz - 0.05;
		}
	}

        geometry_msgs::PoseStamped c_r_msg;
	c_r_msg.pose.position.x=c_r_px;
	c_r_msg.pose.position.y=c_r_py;
	c_r_msg.pose.position.z=c_r_pz;
	c_r_msg.pose.orientation.w=1.0;
   	c_r_pub.publish(c_r_msg);

	geometry_msgs::PoseStamped c_g_msg;
	c_g_msg.pose.position.x=c_g_px;
	c_g_msg.pose.position.y=c_g_py;
	c_g_msg.pose.position.z=c_g_pz;
	c_g_msg.pose.orientation.w=1.0;
   	c_g_pub.publish(c_g_msg);

	geometry_msgs::PoseStamped c_b_msg;
	c_b_msg.pose.position.x=c_b_px;
	c_b_msg.pose.position.y=c_b_py;
	c_b_msg.pose.position.z=c_b_pz;
	c_b_msg.pose.orientation.w=1.0;
   	c_b_pub.publish(c_g_msg);

        r.sleep();
    }
}

int main( int argc, char** argv )
{
    ros::init(argc, argv, "uma_animator");
    ros::NodeHandle n;
    BSR_OO instance(&n);
    instance.run();
}

