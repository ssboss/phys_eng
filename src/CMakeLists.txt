cmake_minimum_required(VERSION 3.31)

set(SOURCES
    particle/particle.cpp
    physics/kinematics/kinematics.cpp
    physics/dynamics/dynamics.cpp
    vector/vector3D.cpp
    engine/engine.cpp
    simulation/sim.cpp
)

set(HEADERS
    particle/particle.h
    physics/kinematics/kinematics.h
    physics/dynamics/dynamics.h
    vector/vector3D.h
    engine/engine.h
    simulation/sim.h
)

add_library(engine_math ${SOURCES} ${HEADERS})

target_link_libraries(engine_math PUBLIC glad glfw glm::glm)

target_include_directories(engine_math PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)