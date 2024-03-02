/*************************************************************************
 * SOURCE: Satelite
 * Description
 *************************************************************************/

#include "Satellite.h"
using namespace std;

Satellite::Satellite(Position position, double dx, double dy, double angle) : 
   position(position), dx(dx), dy(dy), angle(angle) {}

Sputnik::Sputnik(Position position, double dx, double dy, double angle) : Satellite(position, dx, dy, angle) {}

// update ships position and velocity based off of how much time has passed
void Sputnik::update(double timeElapsed) {
   double x = position.getMetersX();
   double y = position.getMetersY();
   updatePositionAndVelocity(x, y, dx, dy, timeElapsed);
   position.setMetersX(x);
   position.setMetersY(y);



}

void Sputnik::draw(ogstream& gout) const {
   gout.drawSputnik(position, angle);
}

