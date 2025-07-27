#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "../include/Object.h"
#include <glm/glm.hpp>
Object::Object(const std::string& name,
        int id,
        glm::vec3 init_pos,
        glm::vec3 init_vel,
        glm::vec3 init_acc
        ):
        name(name),
        id(id),
        position(init_pos),
        velocity(init_vel),
        acceleration(init_acc) {}

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
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        
    float r=50;
    for (int i = 0; i <= 100; i++){
            float angle = 2.0f * 3.14159265f * i / 100;
            float x = position.x + cos(angle) * r;
            float y = position.y + sin(angle) * r;
            glVertex2d(x, y);
        }

     glEnd();
}
