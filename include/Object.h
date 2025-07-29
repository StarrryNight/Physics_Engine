//object class header file


#ifndef OBJECT_H
#define OBJECT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <string>
#include <glm/glm.hpp>
#include "../include/Shader.h"

class Object{
    public:  
        Object(const std::string& name,
        int id,
        Shader* shader,
        glm::vec3 init_pos = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 init_vel = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 init_acc = glm::vec3(0.0f, 1500.0f, 0.0f)
        );

        void setup();
        void disrupt(
        glm::vec3 ds = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 dv = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 da = glm::vec3(0.0f, 0.0f, 0.0f));

        void update(
            float dt
        );

        void render();


        private:
            const std::string& name;
            int id;
            glm::vec3 position;
            glm::vec3 velocity;
            glm::vec3 acceleration;
            Shader* shader;
            unsigned int VAO, VBO;
};

#endif