cmake_minimum_required(VERSION 3.31)

# Proj Name, better name pending
project(physics_engine
    VERSION 0.1.0
    LANGUAGES CXX C
)

set(BUILD_TESTING OFF CACHE BOOL "" FORCE) # using this to toggle between debug and prod builds

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 # tag for GLFW 3.4
)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	0af55ccecd98d4e5a8d1fad7de25ba429d60e863 #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

FetchContent_MakeAvailable(glfw)

add_subdirectory(external)

add_subdirectory(src)

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(src/testing)
endif()

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE engine world core dynamics kinematics particle vector3D)