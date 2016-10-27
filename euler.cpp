#include "euler.h"
#include "solarsystem.h"

Euler::Euler() { }

void Euler::integrateOneStep(SolarSystem &system, double dt)
{
    system.calculateForcesAndEnergy();

    for(CelestialBody &body : system.bodies()) {
        body.position += body.velocity*dt;
        body.velocity += body.force / body.mass * dt;
    }
}
