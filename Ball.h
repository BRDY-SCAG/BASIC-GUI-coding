/**
 * Ball declaration
**/
#ifndef BALL_H
#define BALL_H
#include "Shape.h"

class Ball : public Shape
{
 public:
    Ball(int initialX, int initialY, int size, Fl_Color color, int directionX, int directionY);
    virtual void draw() override;
 private:
};
#endif // BALL_H