#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "../include/Object.h"
#include "../include/Vect3.h"

Object::Object(const std::string& name,
        int id,
        Vect3 init_pos,
        Vect3 init_vel,
        Vect3 init_acc
        ):
        name(name),
        id(id),
        position(init_pos),
        velocity(init_vel),
        acceleration(init_acc) {}

void Object::disrupt(
        Vect3 ds,
        Vect3 dv,
        Vect3 da){
            position.add(ds);
            velocity.add(dv);
            acceleration.add(da);
        }

void Object::update(float dt){
    //change x
    velocity = velocity.add(acceleration.mult(dt));
    position = position.add(velocity.mult(dt));

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
