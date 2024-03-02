#pragma once

// Function declarations
double calculateAltitude(double x, double y);
double calculateGravity(double x, double y);
double calculateGravityDirection(double x, double y);
double calculateHorizontalAcceleration(double x, double y);
double calculateVerticalAcceleration(double x, double y);
void updatePositionAndVelocity(double& x, double& y, double& dx, double& dy, double elapsedTime);

