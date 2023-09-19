/**
 * Ball method implementations
**/
#include <iostream>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "Ball.h"

/**
 * Constructor
**/
Ball::Ball(int initialX, int initialY, int size, Fl_Color color, int directionX,
           int directionY)
      : Shape(initialX, initialY, size, color, directionX, directionY)
{
    // nothing to do here, for now
    //std::cout << "Ball constructor\n";
}

/**
 * Draw the ball shape using fl_pie() with a full circle of degrees (0-360)
 * - size is used twice in fl_pie for a circle (not an ellipse)
**/
void Ball::draw()
{
    //std::cout << "ball at (" << positionX << "," << positionY << ")\n";
    fl_color(color);
    fl_pie(positionX, positionY, size, size, 0, 360);
}
