/**
* GameEngine Implementation
**/
#include <iomanip>
#include <iostream>
#include <random>
#include <string.h>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "GameEngine.h"
#include <vector>

/**
* Constructor
* @param xPos, yPos are the position of the main arena widget
* @param width, height are the dimensions of the main arena widget
* @param label is the widget label?
**/
GameEngine::GameEngine(int xPos, int yPos, int width, int height,
                       const char* label)
      : Fl_Widget(xPos, yPos, width, height, label)
{   
      for(int i = 0 ; i < 5; i++)
    {
    std::random_device seeder;
    auto randomGen = new std::mt19937(seeder());
    int ix = (*randomGen)() % (width - 30) + xPos;
    int iy = (*randomGen)() % (height - 30) + yPos;
    int size = (*randomGen)() % 20 + 5;
    int dx = (*randomGen)() % 10 + 2;
    int dy = (*randomGen)() % 10 + 2;
    // color RGBs go to 255, but keep them darker
    int red = (*randomGen)() % 150;
    int green = (*randomGen)() % 150;
    int blue = (*randomGen)() % 150;
    //std::cout << "color(" << red << "," << green << "," << blue << ")\n";
    Ball* ball = new Ball(ix, iy, size, fl_rgb_color(red,green,blue), dx, dy);
    balls.push_back(ball);
    }
    for(int i = 0; i < 5; i++)
    {
    std::random_device seeder;
    auto randomGen = new std::mt19937(seeder());
    int ix = (*randomGen)() % (width - 30) + xPos;
    int iy = (*randomGen)() % (height - 30) + yPos;
    int size = (*randomGen)() % 20 + 5;
    int dx = (*randomGen)() % 10 + 2;
    int dy = (*randomGen)() % 10 + 2;
    // color RGBs go to 255, but keep them darker
    int red = (*randomGen)() % 150;
    int green = (*randomGen)() % 150;
    int blue = (*randomGen)() % 150;
    Triangle* triangle = new Triangle(ix, iy, size, fl_rgb_color(red,green, blue), dx, dy);
    triangles.push_back(triangle);
    }
}

/*
* Draw the current game state
**/
void GameEngine::draw()
{
    std::cout << "Draw!\n";
    // debug message
    //std::cerr << "Drawing my widget area! (" << winX1 << "," << winY1
    //     << ") to (" << winX2 << "," << winY2 << ")" << endl;
    // get widget (playing area) dimensions
    windowX1 = x();           // upper left corner X
    windowY1 = y();           // upper left corner Y
    windowX2 = x() + w() - 1; // w() gives widget width
    windowY2 = y() + h() - 1; // h() gives widget height
    // draw the playing area border
    fl_color(FL_DARK_GREEN);
    fl_line(windowX1, windowY1, windowX1, windowY2);
    fl_line(windowX2, windowY1, windowX2, windowY2);
    fl_line(windowX1, windowY1, windowX2, windowY1);
    fl_line(windowX1, windowY2, windowX2, windowY2);
    // tell objects in animation to draw themselves
    for(Ball* ball : balls) 
    {
        ball->draw();
    }
    for(Triangle* triangle: triangles)
    {
        triangle->draw();
    }
}

/**
* Update the game state to a new state
**/
void GameEngine::update()
{
    std::cout << "Update!\n";
    // update the objects in the animation
    for(Ball* ball : balls)
    {
        ball->updatePosition(windowX1, windowY1, windowX2, windowY2);
    }

    for (Triangle* triangle: triangles)
    {
        triangle->updatePosition(windowX1, windowY1, windowX2, windowY2);
    }
    // now that we have updated the game state, tell FLTK
    // to redraw the window (FLTK will eventually call our
    // draw() method, and we'll draw the new game state in there
    Fl::redraw();
}
