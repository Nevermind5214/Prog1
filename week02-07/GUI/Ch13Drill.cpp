/*
g++ Ch13Drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Ch13Drill `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities

int main()
try
{
	using namespace Graph_lib; // our graphics facilities are in Graph_lib

	// 1. Make an 800-by-1000 Simple_window .
	Simple_window win {Point{100,100},800,1000,"Ch13Drill"}; // make a simple window

	// 2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that
	// each square is 100 by 100).
	int x_size = 800;
	int x_grid = 100;
	Lines grid;

	for (int x = 0; x<x_size+x_grid; x+=x_grid)
	{
		grid.add(Point{x,0},Point{x,x_size});
		grid.add(Point{x-1,0},Point{x-1,x_size}); // -1 -es tag kell mert OCD
		grid.add(Point{0,x},Point{x_size,x});
		grid.add(Point{0,x-1},Point{x_size,x-1});
	}

	win.attach(grid);

	// 3. Make the eight squares on the diagonal starting from the top left corner
	// red (use Rectangle).
	Vector_ref<Rectangle> rectangles;

	for (int i = 0; i < 8; ++i)
	{
		rectangles.push_back(new Rectangle{Point{i*100, i*100}, 100, 100});
        rectangles[i].set_fill_color(Color::red);
        win.attach(rectangles[i]);
	}

	// 4. Find a 200-by-200-pixel image (JPEG or GIF) and place three copies of it
	// on the grid (each image covering four squares). If you can’t find an image
	// that is exactly 200 by 200, use set_mask() to pick a 200-by-200 section of
	// a larger image. Don’t obscure the red squares.
	Image i200i1 {Point(0,200),"200x200.jpg"};
	win.attach(i200i1);

	Image i200i2 {Point(400,0),"200x200.jpg"};
	win.attach(i200i2);

	Image i200i3 {Point(0,600),"200x200.jpg"};
	win.attach(i200i3);

	// 5.	Add a 100-by-100 image. Have it move around from square to square
	// when you click the “Next” button. Just put wait_for_button() in a loop
	// with some code that picks a new square for your image.
	Image i100 {Point{0,0},"100x100.jpg"};
	win.attach(i100);

	int i=0;
	while(true)
	{
		++i;
		win.wait_for_button();
		if(i==8)
			{
				i=0;
				i100.move(-700,-700);
			}
		else i100.move(100,100);
		win.set_label("Ch13Drill"); // bUgfIX
	}

}

catch (exception& e) {
	cerr << "Oopsie doopsie wtf happened, exception: " << e.what() << endl;
}

catch (...) {
	cerr << "cerr everything else exception\n";
}