/**
 * Defined methods for abstract class Shape
**/
#include "Shape.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>

/**
 * Constructor
**/
Shape::Shape(int initialX, int initialY, int size, Fl_Color color,
             int directionX, int directionY)
{
    positionX = initialX;
    positionY = initialY;
    this->size = size;
    this->color = color;
    // the magnitude of the direction values become the "speed"
    // of the object
    this->directionX = directionX;
    this->directionY = directionY;
}

/**
 * Position update
 * - this computation peforms a reflective "bounce" off
 *   the animation area edges
**/
void Shape::updatePosition(int windowX1, int windowY1, int windowX2,
                           int windowY2)
{
    // update the position of the bouncing ball
    positionX += directionX;
    positionY += directionY;
    if (positionX < windowX1) {
        // bounce off left edge
        positionX = windowX1;
        directionX = -directionX;
    } else if (positionX > windowX2 - size) {
        // bounce off right edge
        positionX = windowX2 - size;
        directionX = -directionX;
    }
    if (positionY < windowY1) {
        // bounce off top edge
        positionY = windowY1;
        directionY = -directionY;
    } else if (positionY > windowY2 - size) {
        // bounce off bottom edge
        positionY = windowY2 - size;
        directionY = -directionY;
    }
}