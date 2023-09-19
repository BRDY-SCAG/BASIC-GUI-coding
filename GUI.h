/**
 * GUI classes for Animation window
**/
#ifndef GUI_H
#define GUI_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Window.H>
#include "GameEngine.h"

class MainWindow : public Fl_Window
{
 public:
    MainWindow(int width, int height, const char* label);
 private:
    GameEngine* game;
};

#endif