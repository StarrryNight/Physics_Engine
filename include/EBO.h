#ifndef EBO_H
#define EBO_H

#include "../include/glad.h"

class EBO{
    public:
    GLuint ID;
    EBO(unsigned int* indices, GLsizeiptr size);

    void Bind();
    void Unbind();
    void Delete();
};


#endif