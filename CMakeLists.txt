cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Cube_project VERSION 1.0)

cmake_policy(SET CMP0072 NEW)
find_package(OpenGL REQUIRED)

# Add the executable
add_executable(Cube_project 
src/main.cpp
includes/glad.c 
includes/glad.h
src/openConf.cpp
src/openConf.h)

target_link_libraries(Cube_project 
glfw
OpenGL::GL)