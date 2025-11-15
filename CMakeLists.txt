cmake_minimum_required(VERSION 3.31)

# Proj Name, better name pending
project(physics_engine
    VERSION 0.1.0
    LANGUAGES CXX    
)

add_subdirectory(src)


include(CTest)

if(BUILD_TESTING)
    add_subdirectory(src/testing)
endif()

# else()
#     add_executable(${PROJECT_NAME})