cmake_minimum_required(VERSION 3.31)

add_library(vector3D STATIC vector3D.cpp)

target_include_directories(vector3D PUBLIC ${CMAKE_SOURCE_DIR/include})