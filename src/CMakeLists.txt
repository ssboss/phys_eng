set(SOURCES
    particle/particle.cpp
    physics/kinematics.cpp
    vector/vector3D.cpp
)

set(HEADERS
    particle/particle.h
    physics/kinematics.h
    vector/vector3D.h
)

add_library(engine_math ${SOURCES} ${HEADERS})

target_include_directories(${LIBRARY_OUTPUT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})