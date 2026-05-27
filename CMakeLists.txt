cmake_minimum_required(VERSION 3.31)

# Proj Name, better name pending
project(physics_engine
    VERSION 0.1.0
    LANGUAGES CXX    
)

add_subdirectory(src)

include(FetchContent)

FetchContent_Declare(
    GLFW
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 # tag for GLFW 3.4
)

FetchContent_MakeAvailable(glfw)
include(CTest)

if(BUILD_TESTING)
    add_subdirectory(src/testing)
endif()

add_executable(${PROJECT_NAME} /src/)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    glad
    GLFW
    engine_math
)