/**
 * Abstract base class for animated shapes
 * - it is abstract because draw() is unimplemented; each
 *   specific subclass shape must draw itself.
*/
#ifndef SHAPE_H
#define SHAPE_H
#include <FL/Fl.H>
#include <FL/fl_draw.H>

class Shape
{
 public:
    Shape(int initialX, int initialY, int size, Fl_Color color, int directionX,
          int directionY);
    void updatePosition(int windowX1, int windowY1, int windowX2, int windowY2);
    virtual void draw() = 0;
 protected:
    int positionX;
    int positionY;
    int size;
    Fl_Color color;
    int directionX;
    int directionY;
};
#endif // SHAPE_H