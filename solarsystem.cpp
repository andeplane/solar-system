#include "solarsystem.h"

SolarSystem::SolarSystem()
{
}

void SolarSystem::addCelestialBody(CelestialBody newObject) {
    objects.push_back(newObject);
}
