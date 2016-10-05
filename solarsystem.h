#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "celestialbody.h"
#include <vector>

class SolarSystem
{
public:
    SolarSystem();
    CelestialBody &createCelestialBody(vec3 position, vec3 velocity, double mass);
    void calculateForcesAndEnergy();
    int numberOfBodies() const;

    double totalEnergy() const;
    double potentialEnergy() const;
    double kineticEnergy() const;
    vec3 angularMomentum() const;
    std::vector<CelestialBody> &bodies();

private:
    std::vector<CelestialBody> m_bodies;
    vec3 m_angularMomentum;
    double m_kineticEnergy;
    double m_potentialEnergy;
};

#endif // SOLARSYSTEM_H
