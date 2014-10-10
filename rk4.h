#ifndef RK4_H
#define RK4_H
#include <solarsystem.h>

class RK4
{
public:
    RK4();
    void integrate(SolarSystem &system, double dt);
};

#endif // RK4_H
