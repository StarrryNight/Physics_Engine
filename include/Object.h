//object class header file


#ifndef OBJECT_H
#define OBJECT_H

#include "../include/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include "../include/Shader.h"
#include "../include/VAO.h"
#include "../include/VBO.h"
#include "../include/EBO.h"

class Object{
    public:  
        Object(const std::string& name,
        int id,
        Shader* shader,
        glm::vec3 init_pos = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 init_vel = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 init_acc = glm::vec3(0.0f, 0.0f, 0.0f)
        );

        void setup();
        void setup(float sphereRadius);
        void disrupt(
        glm::vec3 ds = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 dv = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 da = glm::vec3(0.0f, 0.0f, 0.0f));

        void update(
            float dt
        );

        void render();

        glm::vec3 getPosition() const { return position; }
        glm::vec3 getVelocity() const { return velocity; }
        glm::vec3 getAcceleration() const { return acceleration; }

        private:
            const std::string& name;
            int id;
            glm::vec3 position;
            glm::vec3 velocity;
            glm::vec3 acceleration;
            Shader* shader;
            VAO VAO1;
            VBO* VBO1;
            EBO* EBO1;
            int sphereIndices;
};

#endif