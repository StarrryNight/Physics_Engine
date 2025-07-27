//object class header file


#ifndef OBJECT_H
#define OBJECT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "../include/Vect3.h"
class Object{
    public:  
        Object(const std::string& name,
        int id,
        
        Vect3 init_pos = Vect3{0,0,0},
        Vect3 init_vel = Vect3{0,0,0},
        Vect3 init_acc = Vect3{0,98.1,0}
        );


        void disrupt(
        Vect3 ds = Vect3{0,0,0},
        Vect3 dv = Vect3{0,0,0},
        Vect3 da = Vect3{0,0,0});

        void update(
            float dt
        );

        void render();


        private:
            const std::string& name;
            int id;
            Vect3 position;
            Vect3 velocity;
            Vect3 acceleration;
};

#endif