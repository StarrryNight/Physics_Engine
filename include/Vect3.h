#ifndef VECT3_H
#define VECT3_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

struct Vect3{

    float x;
    float y;
    float z;

    Vect3 add(Vect3 vec);

    Vect3 mult(float f);
};

#endif