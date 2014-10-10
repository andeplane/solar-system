#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

class CelestialBody
{
public:
    double position[3];
    double velocity[3];
    double force[3];
    double mass;

    CelestialBody(double x, double y, double z, double vx, double vy, double vz, double mass_);
    void resetForce();
};

#endif // CELESTIALBODY_H
