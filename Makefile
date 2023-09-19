#
# Makefile for a simple bouncing animation
#
C++ = g++
CXXFLAGS = -Wall -std=c++11 -I/opt/homebrew/Cellar/fltk/1.3.8_1/include
LDLIBS = -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -lfltk -lstdc++
# for MacOs or other personal installations of FLTK, you may
# need to specify the location of the include and library
# files; comment out the definitions above, and uncomment the
# ones below, and fix the path to be the correct one for your system
#CXXFLAGS = -Wall -std=c++11 -I/opt/homebrew/Cellar/fltk/1.3.8_1/include
#LDLIBS = -L/opt/homebrew/Cellar/fltk/1.3.8_1/lib -lfltk -lstdc++

bouncer: main.o GUI.o GameEngine.o Ball.o Shape.o Triangle.o
	$(C++) -o $@ $^ $(LDLIBS)

clean:
	rm -f *~
	rm -f *.o
	rm -f bouncer

dox:
	doxygen Doxyfile