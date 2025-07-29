#ifndef SHADER_H
#define SHADER_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <glm/glm.hpp>
#include <string>

class Shader {
public:
    unsigned int ID;

    // Constructor - loads, compiles, and links shaders
    Shader(const char* vertexPath, const char* fragmentPath);
    
    // Use/activate the shader
    void Use();
    
    // Set uniform matrix4
    void setMat4(const std::string &name, const glm::mat4 &mat);
};

#endif 