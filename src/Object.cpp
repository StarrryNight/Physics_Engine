#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "../include/Object.h"

Object::Object(const std::string& name,
        int id,
        float x,
        float y,
        float v_ix,
        float v_iy,
        float a_ix,
        float a_iy
        ):
        name(name),
        id(id),
        pos_x(x),
        pos_y(y),
        vel_x(v_ix),
        vel_y(v_iy),
        acc_x(a_ix),
        acc_y(a_iy) {}

void Object::disrupt(
        float dx,
        float dy,
        float dvx,
        float dvy,
        float dax,
        float day){
            pos_x+=dx;
            pos_y += dy;
            vel_x += dvx;
            vel_y += dvy;
            acc_x += dax;
            acc_y += day;
        }

void Object::update(float dt){
    //change x
    vel_x += dt*acc_x;
    pos_x += dt*vel_x;

    //change y
    vel_y += dt*acc_y;
    pos_y += dt*vel_y;
    std::cout << "dt: " << dt << ", pos: (" << pos_x << ", " << pos_y << ")" << std::endl;
}

void Object::render(){
    float cenX = pos_x;
    float cenY = pos_y;
    float r=50;
    for (int i = 0; i <= 100; i++){
            float angle = 2.0f * 3.14159265f * i / 100;
            float x = cenX + cos(angle) * r;
            float y = cenY + sin(angle) * r;
            glVertex2d(x, y);
        }
}
