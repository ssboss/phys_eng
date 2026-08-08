cmake_minimum_required(VERSION 3.31)

add_library(world STATIC world.cpp)

target_link_libraries(world PRIVATE core dynamics kinematics)


target_include_directories(world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})