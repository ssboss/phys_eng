cmake_minimum_required(VERSION 3.31)

add_executable(kin_1Dtests 1D_tests.cpp)

target_link_libraries(${RUNTIME_OUTPUT_NAME} PRIVATE engine_math)

add_test(1D_kinematics kin_1Dtests COMMAND kin_1Dtests)

