#include "../include/PhysicsManager.h"
#include <cmath>
#include <algorithm>


#define PI 3.14159265358979323846


PhysicsManager::PhysicsManager(float G) : gravitationalConstant(G) {
}

void PhysicsManager::addPlanet(Planets* planet) {
    if (planet!= nullptr) {
        planets.push_back(planet);
    }
}

void PhysicsManager::removePlanet(Planets* planet) {
    auto it = std::find(planets.begin(), planets.end(), planet);
    if (it != planets.end()) {
        planets.erase(it);
    }
}

void PhysicsManager::clearPlanets() {
    planets.clear();
}

void PhysicsManager::updatePhysics(float dt) {
    calculateGravitationalForces();
    
    for (auto planet : planets) {
        if (planet!= nullptr) {
            planet->update(dt);
        }
    }
}

void PhysicsManager::calculateGravitationalForces() {
    for (size_t i = 0; i < planets.size(); i++) {
        if (planets[i] == nullptr) continue;
        
        glm::vec3 totalForce = glm::vec3(0.0f);
        
        for (size_t j = 0; j < planets.size(); j++) {
            if (i == j || planets[j] == nullptr) continue;
            
            glm::vec3 direction = planets[j]->getPosition() - planets[i]->getPosition();
            float distance = glm::length(direction);
            
            if (distance < 0.001f) continue;
            
            direction = glm::normalize(direction);
            
            float mass1 = (4.0f/3.0f) * PI * pow(planets[i]->radius, 3) * planets[i]->density;
            float mass2 = (4.0f/3.0f) * PI * pow(planets[j]->radius, 3) * planets[j]->density;
            
            float forceMagnitude = gravitationalConstant * (mass1 * mass2) / (distance * distance);
            
            totalForce += direction * forceMagnitude;
        }
        
        if (planets[i] != nullptr) {
            float mass = (4.0f/3.0f) * PI * pow(planets[i]->radius, 3) * planets[i]->density;
            glm::vec3 acceleration = totalForce / mass;
            
            planets[i]->disrupt(glm::vec3(0.0f), glm::vec3(0.0f), acceleration);
        }
    }
}
