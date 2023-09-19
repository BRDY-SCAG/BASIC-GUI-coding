/**
 * GameEngine Declaration
 * - this class manages the animation area of the window
 *   and the objects that are in the animation area; its
 *   two main responsibilities are _drawing_ the current
 *   animation (i.e., game) state, and _updating_ the 
 *   animation state. Updating happens on a timer-basis;
 *   each time the timer expires, it invokes update(), and
 *   then this class' update() should in turn tell all 
 *   the objects to update (and manage them, if needed).
 *   Thus it is a "game engine", although this simple 
 *   animation isn't really a game. It does NOT demonstrate
 *   active user input and control in a game.
**/
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "Ball.h"
#include "Triangle.h"
#include <vector>
class GameEngine : public Fl_Widget
{
 public:
    GameEngine(int xPos, int yPos, int width, int height,
               const char* label = 0);
    virtual void draw() override;   // draw the current game state
    void update(); // update to a new game state
 private:
    // upper left and lower right of animated drawing area
    int windowX1, windowY1, windowX2, windowY2;
    // "game" objects, currently just one
    std::vector<Ball*> balls; 
    std::vector<Triangle*> triangles;
};

#endif