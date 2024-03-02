/*************************************************************
 * 1. Name:
 *      Jason Geppelt and Ebenezer Mensah
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      To make our satellite orbit in the Geostationary orbit (GEO)
 * 5. How long did it take for you to complete the assignment?
 *      13 Hours
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "simulator.h"
#include "physics.h"
using namespace std;

// define static member variable of position class
double Position::metersFromPixels = 40.0;

/*************************************
 * CALLBACK
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // Cast the void pointer into a game object.
   Simulator* pSim = (Simulator*)p;

   // update and draw simulator
   pSim->update();
   pSim->draw();

   
    
 
}

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
int main(int argc, char** argv)
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL, "Orbit", ptUpperRight);

   // Initialize the Simulator
   Simulator sim(ptUpperRight);

   // set everything into action
   ui.run(callBack, &sim);

   return 0;
}
