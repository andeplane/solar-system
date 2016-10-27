#include "solarsystem.h"
#include "velocityverlet.h"

VelocityVerlet::VelocityVerlet() :
    m_firstStep(true)
{

}

void VelocityVerlet::integrateOneStep(SolarSystem &system, double dt) {
    if(m_firstStep) {
        system.calculateForcesAndEnergy();
        m_firstStep = false;
    }

    for(CelestialBody &body : system.bodies()) {
        body.velocity += body.force/body.mass*dt*0.5;
        body.position += body.velocity*dt;
    }

    system.calculateForcesAndEnergy();

    for(CelestialBody &body : system.bodies()) {
        body.velocity += body.force/body.mass*dt*0.5;
    }
}
