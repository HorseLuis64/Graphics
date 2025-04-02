cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Cube_project VERSION 1.0)

cmake_policy(SET CMP0072 NEW)
find_package(OpenGL REQUIRED)

file(GLOB SOURCES "src/*.cpp")

file(GLOB C_SOURCES "includes/*.c")

# Combina todos los archivos fuente (.cpp y .c)
list(APPEND SOURCES ${C_SOURCES})

# Crea el ejecutable con todos los archivos encontrados
add_executable(Cube_project ${SOURCES})

target_include_directories(Cube_project PUBLIC includes)

target_link_libraries(Cube_project 
glfw
OpenGL::GL)