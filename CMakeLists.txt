cmake_minimum_required(VERSION 3.10)
project(renderer)

set(CMAKE_CXX_STANDARD 17)
add_executable(renderer
    src/main.cpp
    src/Object.cpp
    src/Vect3.cpp
    src/glad.c
    src/Shader.cpp
)

target_link_libraries(renderer GL glfw)