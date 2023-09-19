/**
 * Ball method implementations
**/
#include <iostream>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "Triangle.h"

/**
 * Constructor
**/
Triangle::Triangle(int initialX, int initialY, int size, Fl_Color color, int directionX,
           int directionY)
      : Shape(initialX, initialY, size, color, directionX, directionY)
{
    // nothing to do here, for now
    //std::cout << "Triangle constructor\n";
}

/**
 * Draw the ball shape using fl_pie() with a full circle of degrees (0-360)
 * - size is used twice in fl_pie for a circle (not an ellipse)
**/
void Triangle::draw()
{
    //std::cout << "ball at (" << positionX << "," << positionY << ")\n";
    fl_color(color);
    fl_polygon((positionX) - (directionX), positionY - (directionY), positionX + (directionX),positionY - directionY, positionX, positionY + (directionY));
}
