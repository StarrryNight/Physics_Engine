
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
    
    
    VAO1.Bind();

    VBO1 = VBO(vertices, sizeof(vertices));
    
    VAO1.LinkVBO(VBO1,0);
    VAO1.Unbind();
    VBO1.Unbind();

    
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
        
        // Create model matrix for positioning
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, position);  // Move to object's position
        
        // Set the model matrix in shader
        shader->setMat4("model", model);
    }
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
