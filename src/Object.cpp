
#include "../include/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include "../include/Object.h"
#include "../include/Shader.h"
#include "../include/VAO.h"
#include "../include/VBO.h"
#include "../include/EBO.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Object::Object(const std::string& name,
        int id,
        Shader* shaderProgram,
        glm::vec3 init_pos,
        glm::vec3 init_vel,
        glm::vec3 init_acc
        ):
        name(name),
        id(id),
        shader(shaderProgram),
        position(init_pos),
        velocity(init_vel),
        acceleration(init_acc),
        VAO1() {}

void Object::setup() {
    setup(0.5f); // Default radius
}

void Object::setup(float sphereRadius) {
    // Generate sphere vertices and indices
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    
    const float radius = sphereRadius;
    const int sectors = 20;  // Number of horizontal divisions
    const int stacks = 20;   // Number of vertical divisions
    
    // Generate vertices
    for (int i = 0; i <= stacks; ++i) {
        float stackAngle = M_PI / 2 - i * M_PI / stacks;
        float xy = radius * cosf(stackAngle);
        float z = radius * sinf(stackAngle);
        
        for (int j = 0; j <= sectors; ++j) {
            float sectorAngle = j * 2 * M_PI / sectors;
            
            float x = xy * cosf(sectorAngle);
            float y = xy * sinf(sectorAngle);
            
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
    }
    
    // Generate indices
    for (int i = 0; i < stacks; ++i) {
        int k1 = i * (sectors + 1);
        int k2 = k1 + sectors + 1;
        
        for (int j = 0; j < sectors; ++j, ++k1, ++k2) {
            if (i != 0) {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }
            
            if (i != (stacks - 1)) {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }
    
    // Convert to arrays for VBO and EBO
    float* vertexArray = new float[vertices.size()];
    std::copy(vertices.begin(), vertices.end(), vertexArray);
    
    unsigned int* indexArray = new unsigned int[indices.size()];
    std::copy(indices.begin(), indices.end(), indexArray);
    
    VAO1.Bind();
    VBO1 = new VBO(vertexArray, vertices.size() * sizeof(float));
    EBO1 = new EBO(indexArray, indices.size() * sizeof(unsigned int));
    
    VAO1.LinkVBO(*VBO1, 0);
    VAO1.Unbind();
    VBO1->Unbind();
    EBO1->Unbind();
    
    sphereIndices = indices.size();
    
    // Clean up
    delete[] vertexArray;
    delete[] indexArray;
}

void Object::disrupt(
        glm::vec3 ds,
        glm::vec3 dv,
        glm::vec3 da){
           position += ds;
           velocity += dv;
           acceleration += da;
        }

void Object::update(float dt){
    velocity += acceleration*dt;
    position += velocity*dt;
    
    acceleration = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Object::render(){
    if (shader != nullptr) {
        shader->Use();
        
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);  
        
        // Set the model matrix in shader
        shader->setMat4("model", model);
    }
    glBindVertexArray(VAO1.ID);
    glDrawElements(GL_TRIANGLES, sphereIndices, GL_UNSIGNED_INT, 0);
}
