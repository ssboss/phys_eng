cmake_minimum_required(VERSION 3.31)

add_library(core INTERFACE)

target_link_libraries(core INTERFACE vector3D particle)

target_include_directories(core INTERFACE ${CMAKE_SOURCE_DIR/include})
