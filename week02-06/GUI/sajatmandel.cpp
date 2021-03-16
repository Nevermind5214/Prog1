/*
g++ sajatmandel.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o sajatmandel `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include <complex>

#define WIDTH 600
#define HEIGHT 600

int value (int x, int y)  {
	complex<float> point((float)x/WIDTH-1.5, (float)y/HEIGHT-0.5);
	complex<float> z(0, 0);
	int iter = 0;
	while (abs (z) < 2 && iter <= 20) {
		z = z * z + point;
		++iter;
	}
	if (iter < 20) return 1;
	else return 0;
}

int main()
try
{
	using namespace Graph_lib;

	Simple_window win {Point{0, 0}, WIDTH, HEIGHT, "Mandelbrot"};

	Vector_ref<Rectangle> rectangles;

	for (int i = 0; i < WIDTH; ++i)
	{
		for (int j = 0; j < HEIGHT; ++j)
		{
			if(value(i,j)){
				rectangles.push_back(new Rectangle{Point{i, j}, 1, 1});
				win.attach(rectangles[rectangles.size()-1]);
			}
		}
	}

	win.wait_for_button();
}

catch (exception& e) {
	cerr << "Oopsie doopsie wtf happened, exception: " << e.what() << endl;
}

catch (...) {
	cerr << "cerr everything else exception\n";
}