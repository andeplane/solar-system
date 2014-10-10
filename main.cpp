#include <iostream>
#include <cmath>

#include <solarsystem.h>
#include <rk4.h>

using namespace std;

int main()
{
    SolarSystem mySolarSystem;
    CelestialBody sun(vec3(0,0,0), vec3(0,0,0), 1.0);
    CelestialBody earth(vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 3e-6);

    mySolarSystem.addCelestialBody(sun);
    mySolarSystem.addCelestialBody(earth);

    for(int i = 0; i<mySolarSystem.bodies.size(); i++) {
        CelestialBody &thisBody = mySolarSystem.bodies[i];
        cout << "The position of this object is " << thisBody.position << " with velocity " << thisBody.velocity << endl;
    }

    cout << "I just created my first solar system that has " << mySolarSystem.bodies.size() << " objects." << endl;
    return 0;
}

