/**
 * Ball declaration
**/
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
 public:
    Triangle(int initialX, int initialY, int size, Fl_Color color, int directionX, int directionY);
    virtual void draw() override;
 private:
};
#endif // BALL_H