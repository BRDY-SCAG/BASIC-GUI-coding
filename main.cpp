/**
 * Bouncer Main
 **/
#include <iostream>
#include "GUI.h"

/**
 * Program main: construct window and game object,
 * then turn control over to GUI system
 **/
int main(int argc, char* argv[])
{
    // create a GUI window object
    MainWindow mainWindow(500, 500, "Animation Fun");
    // display the window
    mainWindow.show(argc, argv);
    // standard way to run an FLTK GUI app
    return (Fl::run());
}
