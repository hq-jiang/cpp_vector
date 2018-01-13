project(vector)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(sources main.cpp vector.cpp vector.h)
add_executable(${PROJECT_NAME} ${sources})

