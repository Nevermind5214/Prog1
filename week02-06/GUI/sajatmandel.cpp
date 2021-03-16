/*
g++ sajatmandel.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o sajatmandel `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
#include <FL/Fl_Image.H>

int main()
try
{

	using namespace Graph_lib; // our graphics facilities are in Graph_lib

	int xmax = 600; // ablak felbontása x
	int ymax = 400; // ablak felbontása y
	int x_orig = xmax/2; // ablak origója x
	int y_orig = ymax/2; // ablak origója y



	Point origo {x_orig, y_orig}; // ablak origó koordinátái point típusban

	Point tl {100,100}; // to become top left corner of window

	Simple_window win {tl,xmax,ymax,"My window"}; // make a simple window


	char buffer[128];
	
    fl_draw_image_mono(buffer+drawn*W,x()+3,yy,W,1,1,W);
	fl_draw_image_mono(const uchar*, 0, 0, 600, 600, int D = 1, int LD = 0)

	win.wait_for_button(); // give control to the display engine

}

catch (exception& e) {
	cerr << "Oopsie doopsie wtf happened, exception: " << e.what() << endl;
}

catch (...) {
	cerr << "cerr everything else exception\n";
}