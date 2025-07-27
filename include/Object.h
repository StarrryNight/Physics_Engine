//object class header file


#ifndef OBJECT_H
#define OBJECT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

class Object{
    public:  
        Object(const std::string& name,
        int id,
        float x = 0,
        float y = 0,
        float v_ix = 0,
        float v_iy = 0,
        float a_ix = 0,
        float a_iy = 9.81);


        void disrupt(
        float dx = 0,
        float dy = 0,
        float dvx = 0,
        float dvy = 0,
        float dax = 0,
        float day = 0);

        void update(
            float dt
        );

        void render();
        private:
            const std::string& name;
            int id;
            float pos_x = 0;
            float pos_y = 0;
            float vel_x = 0;
            float vel_y = 0;
            float acc_x = 0;
            float acc_y = 0;
};

#endif