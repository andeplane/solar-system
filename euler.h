#ifndef EULER_H
#define EULER_H


class Euler
{
public:
    Euler();
    void integrateOneStep(class SolarSystem &system, double dt);
};

#endif // EULER_H
