#pragma once
#include <librealsense2/rs.hpp>
#include <iostream>
#include <iomanip>
#include "jlcxx/jlcxx.hpp"

class T265 {
    private:
        rs2::pipeline pipe;
        rs2::config cfg;
        std::string serial;

    public:
        T265();
        std::vector<double> get_translation();
        std::vector<double> get_orientation();
        std::vector<double> get_linear_velocity();
        std::vector<double> get_linear_acceleration();
        std::vector<double> get_angular_velocity();
        std::vector<double> get_angular_acceleration();
};

JLCXX_MODULE define_julia_module(jlcxx::Module& types)
{
    types.add_type<T265>("T265")
        .method("get_translation", [](T265& t){
            std::vector<double>pose = t.get_translation();
            jlcxx::Array<double>apose;
            for (auto p : pose)
                apose.push_back(p);
            return apose;
        })
        .method("get_orientation", [](T265& t){
            std::vector<double>pose = t.get_orientation();
            jlcxx::Array<double>apose;
            for (auto p : pose)
                apose.push_back(p);
            return apose;
        })
        .method("get_linear_velocity", [](T265& t){
            std::vector<double>pose = t.get_linear_velocity();
            jlcxx::Array<double>apose;
            for (auto p : pose)
                apose.push_back(p);
            return apose;
        })
        .method("get_linear_acceleration", [](T265& t){
            std::vector<double>pose = t.get_linear_acceleration();
            jlcxx::Array<double>apose;
            for (auto p : pose)
                apose.push_back(p);
            return apose;
        })
        .method("get_angular_velocity", [](T265& t){
            std::vector<double>pose = t.get_angular_velocity();
            jlcxx::Array<double>apose;
            for (auto p : pose)
                apose.push_back(p);
            return apose;
        })
        .method("get_angular_acceleration", [](T265& t){
            std::vector<double>pose = t.get_angular_acceleration();
            jlcxx::Array<double>apose;
            for (auto p : pose)
                apose.push_back(p);
            return apose;
        });
}