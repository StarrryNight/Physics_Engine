#ifndef VAO_H
#define VAO_H
#include "../include/glad.h"
#include "VBO.h"

class VAO{
    public:
        int ID;
        VAO();

        void LinkVBO(VBO VBO, int layout);
        void Bind();
        void Unbind();
        void Delete();
};

#endif