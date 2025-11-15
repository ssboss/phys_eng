cmake_minimum_required(VERSION 3.31)

add_executable(kin_1Dtests 1D_tests.cpp)

target_link_libraries(kin_1Dtests PRIVATE engine_math)

add_test(1D_kinematics kin_1Dtests COMMAND kin_1Dtests)

