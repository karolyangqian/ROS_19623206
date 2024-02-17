#include "ros/ros.h"
#include "tugas1/commandSRV.h"

bool land(tugas1::commandSRV::Request &req, tugas1::commandSRV::Response &resp) {
    if (req.command == "land")
    {
        resp.response = "success"; 
    }
    else
    {
        resp.response = "failed";
    }
    

    // ROS_INFO(
    //     "\n[Server]\n"
    //     "Nilai komponen X: %lf Nilai komponen Y: %lf Nilai komponen Z: %lf\n"
    //     "Magnitude: %lf\n",
    //     req.komponenX,
    //     req.komponenY,
    //     req.komponenZ,
    //     resp.magnitude
    // );
    return true;
}

int main(int argc, char **argv)
{
    ros::init( argc, argv, "magnitude_server");

    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("commandSRV", land);

    ros::spin();

    return 0;
}
