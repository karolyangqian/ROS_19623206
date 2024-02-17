#include "ros/ros.h"
#include "tugas1/DronePos.h"
#include "commander.hpp"
#include "tugas1/commandSRV.h"
#include "Vec3i.hpp"

void callbackHandler(const tugas1::DronePos::ConstPtr &msg) {
    commander commander;
    Vec3i dronePos = {msg->x, msg->y, msg->z};
    Vec3i d = dronePos - commander.getPose();

    ROS_INFO("\nMENGGERAKKAN DRONE:\nx: %lf\ny: %lf\nz: %lf\nstatus: %s\n ",
        msg->x, 
        msg->y, 
        msg->z, 
        msg->status.c_str()
        );
}

int main(int argc, char ** argv){
    ros::init(argc,argv,"commander");

    ros::NodeHandle nh;

    ros::Subscriber data_subscriber = nh.subscribe("drone_status", 1000, callbackHandler);
    ros::ServiceClient client = nh.serviceClient<tugas1::commandSRV>("command");

    ros::spin();

    return 0;
}