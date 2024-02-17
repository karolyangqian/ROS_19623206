#include "ros/ros.h"
#include "tugas1/DronePos.h"
#include "navigator.hpp"
#include "tugas1/commandSRV.h"

bool landCallback(tugas1::commandSRV::Request &req, tugas1::commandSRV::Response &resp) {
    if (req.command == "land")
    {
        resp.response = "success"; 
    }
    else
    {
        resp.response = "failed";
    }

    return true;
}

int main(int argc, char**argv) {
    ros::init(argc,argv,"navigator");

    ros::NodeHandle nh;
    ros::Publisher data_publisher = nh.advertise<tugas1::DronePos>("drone_status", 1000, true);
    ros::ServiceServer server = nh.advertiseService("command", landCallback);

    ros::Rate loop_rate(1);

    navigator navigator;
    navigator.setBounds({0, -1000, 0}, {1000, 0, 10});
    navigator.transform({490, -490, 0});

    int count = 0;

    while(ros::ok() && count < 1000) { 
        tugas1::DronePos msg;

        msg.x = navigator.getPose().x;
        msg.y = navigator.getPose().y;
        msg.z = navigator.getPose().z;
        msg.status = navigator.getStatus();
        navigator.transform({1, -1, 1});

        ROS_INFO("\nMENGIRIM POSE:\nx: %lf\ny: %lf\nz: %lf\nstatus: %s\n ", 
        msg.x, 
        msg.y, 
        msg.z, 
        msg.status.c_str()
        );

        data_publisher.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}