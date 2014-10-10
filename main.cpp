#include <iostream>
#include <solarsystem.h>
#include <cmath>

using namespace std;

int main()
{
    SolarSystem mySolarSystem;
    CelestialBody sun(0, 0, 0, 0, 0, 0, 1.0);
    CelestialBody earth(1, 0, 0, 0, 2*M_PI, 0, 3e-6);

    mySolarSystem.addCelestialBody(sun);
    mySolarSystem.addCelestialBody(earth);

    for(int i = 0; i<mySolarSystem.objects.size(); i++) {
        CelestialBody &thisBody = mySolarSystem.objects[i];
        cout << "The position of this object is " << thisBody.position[0] << ", " << thisBody.position[1] << ", " << thisBody.position[2] << endl;
    }

    cout << "I just created my first solar system that has " << mySolarSystem.objects.size() << " objects." << endl;
    return 0;
}

