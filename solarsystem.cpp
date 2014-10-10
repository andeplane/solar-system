#include "solarsystem.h"

SolarSystem::SolarSystem()
{
}

void SolarSystem::addCelestialBody(CelestialBody newBody) {
    bodies.push_back(newBody);
}

void SolarSystem::calculateForcesAndEnergy()
{
    for(int i=0; i<numberOfBodies(); i++) {
        CelestialBody &body1 = bodies[i];
        for(int j=i+1; j<numberOfBodies(); j++) {
            CelestialBody &body2 = bodies[j];
            vec3 deltaRVector = body1.position - body2.position;
            double dr = deltaRVector.length();
            // Do stuff with
        }

    }
}

int SolarSystem::numberOfBodies()
{
    return bodies.size();
}
