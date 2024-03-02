/*************************************************************************
 * Physics
 * Description
 *************************************************************************/

#include "physics.h"
#include <cmath>

#include <iostream>
using namespace std;



//
//First, calculate gravitational acceleration towards Earth
//

// Constants
const double G = 9.80665; // Gravity at sea level (m/s^2)
const double M = 5.972e24; // Mass of the Earth in kg
const double R = 6378000.0; // Radius of the Earth in meters

// Calculate the altitude of the satellite from the surface of the Earth
double calculateAltitude(double x, double y) {
   
    return sqrt((x * x) + (y * y)) - R;
}

// Calculate gravitational acceleration at the satellite's position
double calculateGravity(double x, double y) {
    double altitude = calculateAltitude(x, y);
    double formEarthCenter = calculateAltitude(x, y) + R;
    //cout // Set precision for floating-point output
     //  << "For a satellite to occupy GEO, it must be " << altitude << " km above the earth (" 
     // << formEarthCenter <<  " km from the center of the earth)." << endl;
    //cout << "My altitude is:  " << altitude << "km" << endl;

    
    return G * pow((R / (R + altitude)), 2);
}

// Calculate the direction of gravity in radians from the satellite's position
double calculateGravityDirection(double x, double y) {
   return atan2((0 - x), (0 - y));
}

// Calculate the horizontal component of the gravitational acceleration towards Earth
double calculateHorizontalAcceleration(double x, double y) {
    double totalAcceleration = calculateGravity(x, y);
    double angle = calculateGravityDirection(x, y);
    return totalAcceleration * sin(angle);
}

// Calculate the vertical component of the gravitational acceleration towards Earth
double calculateVerticalAcceleration(double x, double y) {
    double totalAcceleration = calculateGravity(x, y);
    double angle = calculateGravityDirection(x, y);
    return totalAcceleration * cos(angle);
}


// Function to calculate orbital velocity
double calculateOrbitalVelocity(double altitude) {
   double r = R + altitude; // Distance from the center of the Earth
   return sqrt(G * M / r) ; // Orbital velocity formula
}


//
// Finally, calculate new velocity and position based on time elapsed
// 

void updatePositionAndVelocity(double& x, double& y, double& dx, double& dy, double elapsedTime) {
    // Calculate accelerations
    double ddx = calculateHorizontalAcceleration(x, y);
    double ddy = calculateVerticalAcceleration(x, y);
    double altitude = calculateAltitude(x, y);
    double orbitalVelocity = calculateOrbitalVelocity(altitude) ;
    orbitalVelocity  /= 1000.0;

    // Update velocities
    dx += ddx * elapsedTime;
    dy += ddy * elapsedTime;

    // Convert velocities from m/s to km/s for logging
    double dxKm = dx / 1000.0;
    double dyKm = dy / 1000.0;
 

    //cout << "Horizontal acceleration towards Earth: " << ddx << " m/s^2" << endl;
    //cout << "Vertical acceleration towards Earth: " << ddy << " m/s^2" << endl;
    //cout << "My velocity X is:  " << dxKm << " km/s" << endl;
    //cout << "My velocity Y is:  " << dyKm << " km/s" << endl;
    //cout << "The orbital velocity is  " << orbitalVelocity << " km/s" << endl;
    
    // Update positions
    x += dx * elapsedTime + 0.5 * ddx * pow(elapsedTime, 2);
    y += dy * elapsedTime + 0.5 * ddy * pow(elapsedTime, 2);
}

