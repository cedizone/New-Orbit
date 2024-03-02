/*************************************************************************
 * HEADER: Satelite
 * Description
 *************************************************************************/

#pragma once

#include "position.h"
#include "physics.h"
#include "uiInteract.h"
#include "uiDraw.h"

class Satellite {
public:
    Satellite(Position position, double dx = 0.0, double dy = 0.0, double angle = 0.0);
    virtual void update(double timeElapsed) = 0;
    virtual void draw(ogstream& gout) const = 0;

    void setVelocity(double vX, double vY) { dx = vX, dy = vY; }
    double getDx() { return dx; }
    double getDy() { return dy; }

protected:
    Position position;
    double dx;
    double dy;
    double angle;
};

class Sputnik : public Satellite {
public:
    Sputnik(Position position, double dx = 0.0, double dy = 0.0, double angle = 0.0);
    void update(double timeElapsed) override;
    void draw(ogstream& gout) const override;
};