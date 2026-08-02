cmake_minimum_required(VERSION 3.31)

add_library(world STATIC world.cpp)

target_link_libraries(world PUBLIC particle)
target_link_libraries(world PUBLIC kinematics)
target_link_libraries(world PUBLIC dynamics)

target_include_directories(world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})