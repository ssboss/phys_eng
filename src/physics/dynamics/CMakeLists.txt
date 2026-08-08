cmake_minimum_required(VERSION 3.31)

add_library(dynamics STATIC dynamics.cpp)

target_link_libraries(dynamics PUBLIC particle)

target_include_directories(dynamics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})