#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include <vector>
#include <glm/glm.hpp>
#include "Planets.h"

class PhysicsManager {
private:
    std::vector<Planets*> planets;
    float gravitationalConstant;
    
public:
    PhysicsManager(float G = 6.67430e-11f);
    
    void addPlanet(Planets* planet);
    void removePlanet(Planets* planet);
    void clearPlanets();
    
    void updatePhysics(float dt);
    void calculateGravitationalForces();
    
    // Getters
    const std::vector<Planets*>& getPlanets() const { return planets; }
    float getGravitationalConstant() const { return gravitationalConstant; }
    
    // Setters
    void setGravitationalConstant(float G) { gravitationalConstant = G; }
};

#endif