#ifndef VELOCITYVERLET_H
#define VELOCITYVERLET_H


class VelocityVerlet
{
public:
    VelocityVerlet();
    void integrateOneStep(class SolarSystem &system, double dt);
private:
    bool m_firstStep;
};

#endif // VELOCITYVERLET_H
