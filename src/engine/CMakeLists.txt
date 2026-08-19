cmake_minimum_required(VERSION 3.31)

add_library(engine STATIC engine.cpp)

target_link_libraries(engine PUBLIC glad glfw glm::glm core)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})



