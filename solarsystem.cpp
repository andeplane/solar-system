#include "solarsystem.h"

SolarSystem::SolarSystem()
{
}

void SolarSystem::addCelestialBody(CelestialBody newBody) {
    bodies.push_back(newBody);
}

void SolarSystem::calculateForcesAndEnergy()
{
    kineticEnergy = 0;
    potentialEnergy = 0;
    angularMomentum.setToZero();

    for(int i=0; i<numberOfBodies(); i++) {
        CelestialBody &body1 = bodies[i];
        for(int j=i+1; j<numberOfBodies(); j++) {
            CelestialBody &body2 = bodies[j];
            vec3 deltaRVector = body1.position - body2.position;
            double dr = deltaRVector.length();
            // Calculate the force and potential energy here
        }

        kineticEnergy += 0.5*body1.mass*body1.velocity.lengthSquared();
    }
}

int SolarSystem::numberOfBodies()
{
    return bodies.size();
}

double SolarSystem::totalEnergy()
{
    return kineticEnergy + potentialEnergy;
}
