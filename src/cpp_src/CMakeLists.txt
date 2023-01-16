cmake_minimum_required(VERSION 3.1.0)
project(realpose)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(JlCxx_DIR "/home/alphonsus/software/cxxwrap/libcxxwrap-julia-build")
set(Julia_EXECUTABLE "/home/alphonsus/software/julia/julia-1.6.7-linux-x86_64/julia-1.6.7/bin/julia")

find_package(realsense2)
find_package(JlCxx)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${JlCxx_location}")
set(DEPENDENCIES realsense2)
 
add_library(T265 SHARED t265.cpp)
target_link_libraries(T265 JlCxx::cxxwrap_julia ${DEPENDENCIES} librealsense2.so)

# add_executable(main t265.cpp main.cpp)
# set_property(TARGET main PROPERTY CXX_STANDARD 11)
# target_link_libraries(main ${DEPENDENCIES} librealsense2.so)