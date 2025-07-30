#ifndef EBO_H
#define EBO_H

#include "../include/glad.h"

class VBO{
    public:
    int ID;
    EBO(int* vertices, GLsizeiptr size);

    void Bind();
    Void Unbind();
    void Delete();
};


#endif