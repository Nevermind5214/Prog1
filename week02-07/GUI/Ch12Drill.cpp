/*
g++ Ch12Drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Ch12Drill `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
#include "std_lib_facilities.h" // good ol' library

double one(double) { return 1; } // Mindíg 1-et ad vissza

double square(double x) { return x*x; } // négyzetezi

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

	int xlength = xmax-40;
	int ylength = ymax-40;

	int xscale = 30, yscale = 30;

	int rmin = -11;
	int rmax = 11;

	int n_points = 400;

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength +20}, ylength, ylength/yscale, "y"};
	win.attach(x);
	win.attach(y);

	Function s {one, rmin, rmax , origo, n_points, xscale, yscale};
	win.attach(s);

	Function squaree {square, rmin, rmax , origo, n_points, xscale, yscale};
	win.attach(squaree);

	Function cos_func ( [] (double x) { return cos(x); }, rmin, rmax , origo, n_points, xscale, yscale);
	win.attach(cos_func);


	Function sine {sin,0,100,Point{20,150},1000,50,50}; // sine curve
	// plot sin() in the range [0:100) with (0,0) at (20,150)
	// using 1000 points; scale x values *50, scale y values *50
	win.attach(sine);


	s.set_color(Color::blue);
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);

	Rectangle r {Point{200,200}, 100, 50};
	win.attach(r);

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	poly_rect.add(Point{50,75});

	r.set_fill_color(Color::yellow);

	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);

	Text t {Point{150,350}, "Graphics Design is my Passion!"};
	win.attach(t);

	t.set_font(Font::times_bold);
	t.set_font_size(20);


	Image ii {Point(100,50),"image.jpg"};
	win.attach(ii);

	win.wait_for_button();
	ii.move(100,200);

	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_red);
	win.attach(e);

	Circle c {Point{100,200},50};
	win.attach(c);

	Mark m {Point(100,200),'x'};
	win.attach(m);

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	Image cal {Point{325,125},"snow_cpp.gif"};
	cal.set_mask(Point{40,40},200,150);

	win.attach(sizes);
	win.attach(cal);


	win.wait_for_button(); // give control to the display engine

}

catch (exception& e) {
	cerr << "Oopsie doopsie wtf happened, exception: " << e.what() << endl;
}

catch (...) {
	cerr << "cerr everything else exception\n";
}