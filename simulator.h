/*************************************************************************
 * HEADER: Simulator
 * Description
 *************************************************************************/

#pragma once

#include "position.h"
#include "satellite.h"
#include "uiInteract.h"
#include "uiDraw.h"

class Simulator
{
public:
    Simulator(const Position& ptUpperRight);
    void update();
    void draw() const;

    int getTimeElapsed() { return timeElapsed; }

private:
    Position ptUpperRight;
    Sputnik sputnik;
    double angleEarth;
    double timeElapsed;
    int phaseStar;
    Position ptStar; // Position of a star
    double lastStarTime;
};

