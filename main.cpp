#include <iostream>
#include <cmath>

#include <solarsystem.h>
#include <rk4.h>

using namespace std;

int main()
{
    SolarSystem solarSystem;

    // We create new bodies like this. Note that the createCelestialBody function returns a reference to the newly created body
    // This can then be used to modify properties or print properties of the body if desired
    CelestialBody &sun = solarSystem.createCelestialBody( vec3(0,0,0), vec3(0,0,0), 1.0 );
    CelestialBody &earth = solarSystem.createCelestialBody( vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6 );

    // To get a list (a reference, not copy) of all the bodies in the solar system, we use the .bodies() function
    vector<CelestialBody> &bodies = solarSystem.bodies();
    for(int i = 0; i<bodies.size(); i++) {
        CelestialBody &thisBody = bodies[i]; // Reference to this body
        cout << "The position of this object is " << thisBody.position << " with velocity " << thisBody.velocity << endl;
    }

    cout << "I just created my first solar system that has " << solarSystem.bodies().size() << " objects." << endl;
    return 0;
}

