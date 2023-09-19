#include "GUI.h"
#include "GameEngine.h"
#include <iostream>

// Game frame update rate
#define TIMER_RATE 0.025 // 40 times a second

//-------------------------------------------------------------------
// FLTK Plain C function callbacks
// - most FLTK events work directly with a plain C function rather
//   than an object method; this is a bad design but we deal with it.
//-------------------------------------------------------------------

/**
 * C function callback for exit menu selection
 * - parameters are unused and unimportant
**/
void exitProgram(Fl_Widget* w, void* p)
{
    std::cout << "Program exiting...\n";
    exit(0); // this C library function immediately exits the program!
}

/**
 * C function callback for timer
**/
void timerExpired(void* gp)
{
    static unsigned int timerCount = 0;
    std::cout << "Timer " << timerCount++ << "!\n";
    // cast the void game pointer back into a real GameEngine pointer
    GameEngine* game = static_cast<GameEngine*>(gp);
    game->update();
    Fl::repeat_timeout(TIMER_RATE, timerExpired, gp);
}

/**
 * C function callback for start/stop button
 * -- the game parameter MUST be declared as void* for FLTK,
 *    but when we actually use it in the timerExpired function,
 *    we convert it back to a GameEngine pointer
**/
void startButtonPushed(Fl_Widget* w, void* game)
{
    static bool started = false;
    // cast the widget pointer to a button pointer, because
    // that's what it really is
    Fl_Button* thisButton = dynamic_cast<Fl_Button*>(w);
    if (!started) {
        std::cout << "Starting game...\n";
        // set up our timer
        Fl::add_timeout(TIMER_RATE, timerExpired, game);
        started = true;
        thisButton->label("Stop");
    } else {
        std::cout << "Stopping game...\n";
        Fl::remove_timeout(timerExpired, game);
        started = false;
        thisButton->label("Start");
    }
}

//-------------------------------------------------------------------
// End of plain C function callbacks
//-------------------------------------------------------------------

/**
 * MainWindow constructor
 * - this is where we create our window elements and put them
 *   in the window
**/
MainWindow::MainWindow(int width, int height, const char* label)
      : Fl_Window(width, height, label)
{
    // begin window sub-components
    this->begin();
    // create menu bar
    Fl_Menu_Bar* menu = new Fl_Menu_Bar(0, 0, 500, 30);
    // Add File->Quit menu item and connect it to the callback function
    menu->add("&File/&Quit", "^q", exitProgram);
    // create start/stop button
    Fl_Button* startButton = new Fl_Button(5, 35, 60, 25, "Start");
    // create drawing area object
    game = new GameEngine(0, 70, this->w(), this->h() - 70);
    // declare the drawing area to be resizable
    this->resizable(game);
    // connect button to its callback function, and pass the game
    // object pointer as extra data to the callback
    startButton->callback(startButtonPushed, game);
    // end window sub-components
    this->end();
}