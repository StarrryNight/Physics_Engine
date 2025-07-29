
#include "../include/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <glm/glm.hpp>
#include "../include/Object.h"
#include "../include/Shader.h"


Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    // load, compile, link shaders here
    // store program ID in ID
}

void Shader::Use() {
    glUseProgram(ID);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &mat) {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}