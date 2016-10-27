#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "euler.h"
#include "velocityverlet.h"
#include <ctime>
using namespace std;

int main(int numArguments, char **arguments)
{
    double T = 1.0;
    double dt = 0.001;
    if(numArguments >= 2) T = atof(arguments[1]);
    if(numArguments >= 3) dt = atof(arguments[2]);
    int numTimesteps = T/dt;

    SolarSystem solarSystem;
    // We create new bodies like this. Note that the createCelestialBody function returns a reference to the newly created body
    // This can then be used to modify properties or print properties of the body if desired
    // Use with: solarSystem.createCelestialBody( position, velocity, mass );

    solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
    solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );

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

