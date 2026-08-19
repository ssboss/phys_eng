cmake_minimum_required(VERSION 3.31)

add_library(particle STATIC particle.cpp)

target_link_libraries(particle PUBLIC vector3D)

target_include_directories(particle PUBLIC ${CMAKE_SOURCE_DIR}/include)