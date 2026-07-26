cmake_minimum_required(VERSION 3.31)

add_subdirectory(vector)
add_subdirectory(particle)
add_subdirectory(physics/kinematics)
add_subdirectory(physics/dynamics)
add_subdirectory(world)
add_subdirectory(engine)

#[[
set(SOURCES
    particle/particle.cpp
    vector/vector3D.cpp
    engine/engine.cpp
    world/world.cpp
)

set(HEADERS
    particle/particle.h
    vector/vector3D.h
    engine/engine.h
    world/world.h
)
]]

# add_library(engine_math ${SOURCES} ${HEADERS})



# target_link_libraries(engine_math PUBLIC glad glfw glm::glm)

#[[
target_include_directories(engine_math PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
]]