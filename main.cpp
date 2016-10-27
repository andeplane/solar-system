#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "euler.h"
#include "velocityverlet.h"
#include "random.h"
#include <ctime>
using namespace std;

SolarSystem createSunEarth() {
    SolarSystem solarSystem;
    solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
    solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );
    return solarSystem;
}

SolarSystem createSunEarthAndAsteroids(int N) {
    SolarSystem solarSystem = createSunEarth();
    double G = pow(4*M_PI*M_PI, 1.0/3.0); // Chosen so we get decent orbits

    for(int i=0; i<N; i++) {
        vec3 pos(Random::nextDouble(-5, 5), Random::nextDouble(-5, 5), Random::nextDouble(-5, 5));
        vec3 vel(Random::nextDouble(-G, G), Random::nextDouble(-G, G), Random::nextDouble(-G, G));
        double mass = Random::nextDouble(1e-8, 1e-6);
        solarSystem.createCelestialBody(pos, vel, mass);
    }

    return solarSystem;
}

int main(int numArguments, char **arguments)
{
    double T = 1.0;
    double dt = 0.001;
    if(numArguments >= 2) T = atof(arguments[1]);
    if(numArguments >= 3) dt = atof(arguments[2]);
    int numTimesteps = T/dt;

    // SolarSystem solarSystem = createSunEarth();
    SolarSystem solarSystem = createSunEarthAndAsteroids(100);

    clock_t begin = clock();
    VelocityVerlet integrator;
    // Euler integrator;
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.integrateOneStep(solarSystem, dt);
        solarSystem.writeToFile("positions.xyz");
    }

    double timeElapsed = (clock() - begin) / double(CLOCKS_PER_SEC);
    cout << "Simulation finished using " << timeElapsed << " seconds." << endl;

    return 0;
}

