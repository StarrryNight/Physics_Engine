
#include "../include/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <glm/glm.hpp>
#include "../include/Object.h"
#include "../include/Shader.h"


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
        acceleration(init_acc) {}

void Object::setup() {
    // Initialize vertices for triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
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
    //change x
    velocity += acceleration*dt;
    position += velocity*dt;

    std::cout << "dt: " << dt << ", pos: (" << position.x << ", " << position.y << ")" << std::endl;
}

void Object::render(){
    if (shader != nullptr) {
        shader->Use();
    }
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
