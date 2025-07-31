#ifndef PLANETS_H
#define PLANETS_H

#include "Object.h"

class Planets : public Object {
public:
    float radius;
    float density;
    
    // Constructor
    Planets(const std::string& name,
            int id,
            Shader* shader,
            float planetRadius,
            float planetDensity,
            glm::vec3 init_pos = glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3 init_vel = glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3 init_acc = glm::vec3(0.0f, 0.0f, 0.0f));
    
    // Setup planet with its radius
    void setupPlanet();
};

#endif 