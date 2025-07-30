#ifndef VBO_H
#define VBO_H

#include "../include/glad.h"

class VBO{
    public:
    int ID;
    VBO(int* vertices, int size);

    void Bind();
    void Unbind();
    void Delete();
};


#endif