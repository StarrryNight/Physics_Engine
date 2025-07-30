#include "../include/VBO.h"

VBO:VBO(int* vertices, int size){
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(&vertices), &vertices, GL_STATIC_DRAW)
}

void VBO::Bind(){
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind(){
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void VBO::Delete(){
    glDeleteBuffers(1,&ID);
}