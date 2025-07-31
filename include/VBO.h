#ifndef VBO_H
#define VBO_H

#include "../include/glad.h"

class VBO{
    public:
    GLuint ID;
    VBO(float* vertices, int size);

    void Bind();
    void Unbind();
    void Delete();
};


#endif