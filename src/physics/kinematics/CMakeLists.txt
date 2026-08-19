cmake_minimum_required(VERSION 3.31)

add_library(kinematics STATIC kinematics.cpp)

target_link_libraries(kinematics PUBLIC particle)

target_include_directories(kinematics PUBLIC ${CMAKE_SOURCE_DIR}/include)