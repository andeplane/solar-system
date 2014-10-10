#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <celestialbody.h>
#include <vector>
using std::vector;

class SolarSystem
{
public:
    vector<CelestialBody> bodies;
    double kineticEnergy;
    double potentialEnergy;
    vec3 angularMomentum;

    SolarSystem();
    void addCelestialBody(CelestialBody newBody);
    void calculateForcesAndEnergy();
    int numberOfBodies();
};

#endif // SOLARSYSTEM_H
