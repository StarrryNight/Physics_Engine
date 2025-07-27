#include "../include/Vect3.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>


Vect3 Vect3::add(Vect3 vec){
    return Vect3{x+vec.x, y+vec.y, z+vec.z};
}

Vect3 Vect3::mult(float f){
    return Vect3{x*f, y*f, z*f};
}

