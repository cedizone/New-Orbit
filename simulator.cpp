/*************************************************************************
 * SOURCE: Simulator
 * Description
 *************************************************************************/

#include "simulator.h"
#include "position.h"
#include "Satellite.h"
#include "uiDraw.h"
#include <cmath>

using namespace std;

// Define M_PI for rotating the earth
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



// Constructor initialization
Simulator::Simulator(const Position & ptUpperRight) :
   ptUpperRight(ptUpperRight),
   sputnik(Position(0.0, 42164000.0), -3100.0, 0.0),
   angleEarth(0.0),
   timeElapsed(0),
   phaseStar(0),
   ptStar(Position(0.0, 0.0)),
   lastStarTime(-96.0) {} // Ensure the star is drawn initially

void Simulator::update() {
   const double realTimePerFrame = 48.0; // 48 real-world seconds per frame
   timeElapsed += realTimePerFrame;
   angleEarth -= (2 * M_PI) / (86400 / realTimePerFrame);
   angleEarth = fmod(angleEarth, 2 * M_PI); // Normalize the angle

   if (timeElapsed - lastStarTime >= 96.0) { // Check if 2 seconds have passed
       // It's time to draw a new star
       lastStarTime = timeElapsed;
       phaseStar = random(0, 255); // New phase for twinkling effect
       double randomX = random(-200000000.0, 200000000.0);
       double randomY = random(-200000000.0, 200000000.0);
       ptStar.setMeters(randomX, randomY);
   }

   sputnik.update(realTimePerFrame); // Update satellite state
}

void Simulator::draw() const {
    ogstream gout(ptUpperRight);

    sputnik.draw(gout);

    // Draw the star if within 2 seconds of its appearance
    if (timeElapsed - lastStarTime < 96.0) {
        gout.drawStar(ptStar, phaseStar); // Draw the star
    }

    gout.drawEarth(Position(0, 0), angleEarth);
}