cmake_minimum_required(VERSION 3.31)

add_library(engine STATIC engine.cpp)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(engine PUBLIC particle world glad glfw glm::glm)

# target_link_libraries(engine_math PRIVATE glad glfw glm::glm)

target_include_directories(engine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)