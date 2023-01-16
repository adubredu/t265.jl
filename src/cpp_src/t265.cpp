#include "t265.hpp"
#include "utils.hpp"

T265::T265(){
    if (!device_with_streams({RS2_STREAM_POSE}, serial))
        return;
    
    if (!serial.empty())
        cfg.enable_device(serial);
    
    cfg.enable_stream(RS2_STREAM_POSE, RS2_FORMAT_6DOF);
    pipe.start(cfg);
}

std::vector<double> T265::get_translation(){
    auto frames = pipe.wait_for_frames();
    auto f = frames.first_or_default(RS2_STREAM_POSE);
    auto pose_data = f.as<rs2::pose_frame>().get_pose_data();
    std::vector<double> ret_pose{pose_data.translation.x,
                                pose_data.translation.y,
                                pose_data.translation.z} ;
    return ret_pose;
}

std::vector<double> T265::get_orientation(){
    auto frames = pipe.wait_for_frames();
    auto f = frames.first_or_default(RS2_STREAM_POSE);
    auto pose_data = f.as<rs2::pose_frame>().get_pose_data();
    std::vector<double> ret_pose{pose_data.rotation.w,
                                pose_data.rotation.x,
                                pose_data.rotation.y,
                                pose_data.rotation.z} ;
    return ret_pose;
}

std::vector<double> T265::get_linear_velocity(){
    auto frames = pipe.wait_for_frames();
    auto f = frames.first_or_default(RS2_STREAM_POSE);
    auto pose_data = f.as<rs2::pose_frame>().get_pose_data();
    std::vector<double> ret_pose{pose_data.velocity.x,
                                pose_data.velocity.y,
                                pose_data.velocity.z} ;
    return ret_pose;
}

std::vector<double> T265::get_linear_acceleration(){
    auto frames = pipe.wait_for_frames();
    auto f = frames.first_or_default(RS2_STREAM_POSE);
    auto pose_data = f.as<rs2::pose_frame>().get_pose_data(); 
    std::vector<double> ret_pose{pose_data.acceleration.x,
                                pose_data.acceleration.y,
                                pose_data.acceleration.z} ; 
    return ret_pose;
}

std::vector<double> T265::get_angular_velocity(){
    auto frames = pipe.wait_for_frames();
    auto f = frames.first_or_default(RS2_STREAM_POSE);
    auto pose_data = f.as<rs2::pose_frame>().get_pose_data();
    std::vector<double> ret_pose{pose_data.angular_velocity.x,
                                pose_data.angular_velocity.y,
                                pose_data.angular_velocity.z} ;
    return ret_pose;
}
std::vector<double> T265::get_angular_acceleration(){
    auto frames = pipe.wait_for_frames();
    auto f = frames.first_or_default(RS2_STREAM_POSE);
    auto pose_data = f.as<rs2::pose_frame>().get_pose_data();
    std::vector<double> ret_pose{pose_data.angular_acceleration.x,
                                pose_data.angular_acceleration.y,
                                pose_data.angular_acceleration.z} ;
    return ret_pose;
}