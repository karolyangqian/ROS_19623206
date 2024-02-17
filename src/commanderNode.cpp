#include "ros/ros.h"
#include "tugas1/DronePos.h"
#include "commander.hpp"
#include "tugas1/commandSRV.h"
#include "Vec3i.hpp"

ros::ServiceClient client;
commander cmd;

void callbackHandler(const tugas1::DronePos::ConstPtr &msg) {
    Vec3i dronePos = {msg->x, msg->y, msg->z};
    tugas1::commandSRV srv;


    if (dronePos.x > 500 && dronePos.y < -400 && cmd.getStatus() != "land")
    {
        ros::Rate loop_rate(1);

        while (cmd.getPose().z > 0 && cmd.getPose().z != 0)
        {
            cmd.transform({0, 0, -1});
            cmd.setStatus("landing");

            ROS_INFO("\nLANDING\nx: %lf\ny: %lf\nz: %lf\nstatus: %s\n ",
            cmd.getPose().x, 
            cmd.getPose().y, 
            cmd.getPose().z, 
            cmd.getStatus().c_str()
            );

            loop_rate.sleep();
        }   
        cmd.setStatus("land");
        srv.request.command = cmd.getStatus();
        
        
    }

    if (client.call(srv)){
        if (srv.response.response.c_str() != "success")
        {
            cmd.transform(dronePos - cmd.getPose());
        }
        else
        {
            ROS_INFO("[Client] Response: %s", srv.response.response.c_str());
        }
    }
    else {
        ROS_INFO("[Client] Service gagal dipanggil");
    }
    

    ROS_INFO("\nMENERIMA POSE:\nx: %lf\ny: %lf\nz: %lf\nstatus: %s\n ",
        cmd.getPose().x, 
        cmd.getPose().y, 
        cmd.getPose().z, 
        cmd.getStatus().c_str()
        );
}

int main(int argc, char ** argv){
    ros::init(argc,argv,"commander");

    ros::NodeHandle nh;

    client = nh.serviceClient<tugas1::commandSRV>("command");
    ros::Subscriber data_subscriber = nh.subscribe("drone_status", 1000, callbackHandler);


    ros::spin();

    return 0;
}