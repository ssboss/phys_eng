cmake_minimum_required(VERSION 3.31)

set(SOURCES
    particle/particle.cpp
    physics/kinematics/kinematics.cpp
    vector/vector3D.cpp
    engine/engine.cpp
)

set(HEADERS
    particle/particle.h
    physics/kinematics.h
    vector/vector3D.h
    engine/engine.h
)

add_library(engine_math ${SOURCES} ${HEADERS})

target_include_directories(engine_math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})