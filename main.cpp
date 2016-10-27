#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarsystem.h"
#include "euler.h"
#include "velocityverlet.h"
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

    // We don't need to store the reference, but just call the function without a left hand side
    solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );

    // To get a list (a reference, not copy) of all the bodies in the solar system, we use the .bodies() function
    vector<CelestialBody> &bodies = solarSystem.bodies();

    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &body = bodies[i]; // Reference to this body
        cout << "The position of this object is " << body.position << " with velocity " << body.velocity << endl;
    }

    VelocityVerlet integrator;
    // Euler integrator;
    for(int timestep=0; timestep<numTimesteps; timestep++) {
        integrator.integrateOneStep(solarSystem, dt);
        solarSystem.writeToFile("positions.xyz");
    }

    cout << "I just created my first solar system that has " << solarSystem.bodies().size() << " objects." << endl;
    return 0;
}

