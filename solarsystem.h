#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <celestialbody.h>
#include <vector>
using std::vector;

class SolarSystem
{
public:
    vector<CelestialBody> objects;
    SolarSystem();
    void addCelestialBody(CelestialBody newObject);
};

#endif // SOLARSYSTEM_H
