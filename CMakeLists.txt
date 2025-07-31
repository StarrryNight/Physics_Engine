cmake_minimum_required(VERSION 3.10)
project(renderer)

set(CMAKE_CXX_STANDARD 17)
add_executable(renderer
    src/main.cpp
    src/Object.cpp
    src/Vect3.cpp
    src/glad.c
    src/Shader.cpp
    src/VAO.cpp
    src/VBO.cpp
    src/EBO.cpp
    src/Camera.cpp
    src/Planets.cpp
    src/PhysicsManager.cpp
)

target_link_libraries(renderer GL glfw)