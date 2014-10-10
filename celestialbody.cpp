#include "celestialbody.h"

CelestialBody::CelestialBody(double x, double y, double z, double vx, double vy, double vz, double mass_) {
    position[0] = x;
    position[1] = y;
    position[2] = z;

    velocity[0] = vx;
    velocity[1] = vy;
    velocity[2] = vz;

    mass = mass_;

    resetForce();
}

void CelestialBody::resetForce() {
    // force.zeros(); // Armadillo
    force[0] = 0;
    force[1] = 0;
    force[2] = 0;
}
