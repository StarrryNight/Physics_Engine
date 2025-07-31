#include "../include/Planets.h"

Planets::Planets(const std::string& name,
                 int id,
                 Shader* shader,
                 float planetRadius,
                 float planetDensity,
                 glm::vec3 init_pos,
                 glm::vec3 init_vel,
                 glm::vec3 init_acc)
    : Object(name, id, shader, init_pos, init_vel, init_acc),
      radius(planetRadius),
      density(planetDensity) {
}

void Planets::setupPlanet() {
    setup(radius);
} 