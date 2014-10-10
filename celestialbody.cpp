#include "celestialbody.h"

CelestialBody::CelestialBody(vec3 pos, vec3 vel, double mass_) {
    position = pos;
    velocity = vel;
    mass = mass_;

    resetForce();
}

CelestialBody::CelestialBody(double x, double y, double z, double vx, double vy, double vz, double mass_) {
    CelestialBody(vec3(x,y,z), vec3(vx, vy, vz), mass_);
}

void CelestialBody::resetForce() {
    force.setToZero();
}
