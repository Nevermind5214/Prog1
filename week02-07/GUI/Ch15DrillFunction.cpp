/*
g++ Ch15DrillFunction.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Ch15DrillFunction `fltk-config --ldflags --use-images`

2. Note that you’ll need to make a project with the properties specified in the
“installation of FLTK” note from the course website.
3. You’ll need to move Graph.cpp and Window.cpp into your project.

*/

#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

void waitbutton(Simple_window& winner, string mytitle){
	if (mytitle == "") mytitle = "unnamed window";
	winner.set_label(mytitle); // bUgfIX
	winner.wait_for_button();
}

int main() try {
	const int xwin = 600;
	const int ywin = 600;

	const int xorigo = xwin/2;
	const int yorigo = ywin/2;

	const Point origo(xorigo,yorigo);

	const int xscale = 20;
	const int yscale = 20;

	// 1. Make an empty 600-by-600 Window labeled “Function graphs.”
	const string title = "Function graphs";
	Simple_window win(Point{100, 100}, xwin, ywin, title);

	const int xaxislength = 400;
	const int yaxislength = 400;

	// 4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels”
	// and with a notch every 20 pixels. The axes should cross at (300,300).
	Axis x {Axis::x, Point{(xwin-xaxislength)/2,yorigo}, xaxislength, xaxislength/xscale, "1 == 20 pixels"};
	Axis y {Axis::y, Point{xorigo, ywin-(ywin-yaxislength)/2}, yaxislength, yaxislength/yscale,"1 == 20 pixels"};
	
	win.attach(x);
	win.attach(y);

	// 5. Make both axes red.
	x.set_color(Color::red);
	y.set_color(Color::red);

	waitbutton(win, title);

	// 1. Graph the function double one(double x) { return 1; } in the range [–10,11]
	// with (0,0) at (300,300) using 400 points and no scaling (in the window).
	const int rangemin = -10;
	const int rangemax = 11;
	const int numberofpoints = 400;

	// 2. Change it to use x scale 20 and y scale 20.
	// 3. From now on use that range, scale, etc. for all graphs.
	Function onefunc(one,rangemin,rangemax,origo,numberofpoints,xscale,yscale);
	win.attach(onefunc);
	
	waitbutton(win, title);

	// 4. Add double slope(double x) { return x/2; } to the window.
	// 5. Label the slope with a Text "x/2" at a point just above its bottom left end
	// point.
	Function slopefunc(slope,rangemin,rangemax,origo,numberofpoints,xscale,yscale);
	win.attach(slopefunc);

	// 5. Label the slope with a Text "x/2" at a point just above its bottom left end
	// point.
	Text x2label(Point(100,390),"x/2");
	win.attach(x2label);
	
	waitbutton(win, title);

	// 6. Add double square(double x) { return x*x; } to the window.
	Function squarefunc(square,rangemin,rangemax,origo,numberofpoints,xscale,yscale);
	win.attach(squarefunc);
	
	waitbutton(win, title);

	// 7. Add a cosine to the window (don’t write a new function).
	Function cosfunc(cos,rangemin,rangemax,origo,numberofpoints,xscale,yscale);
	win.attach(cosfunc);

	// 8. Make the cosine blue.
	cosfunc.set_color(Color::blue);
	
	waitbutton(win, title);

	// 9. Write a function sloping_cos() that adds a cosine to slope() (as defined
	// above) and add it to the window.
	Function slopingcosfunc(sloping_cos,rangemin,rangemax,origo,numberofpoints,xscale,yscale);
	win.attach(slopingcosfunc);
	
	waitbutton(win, title);
}

catch (exception& e) {
	cerr << "Oopsie doopsie wtf happened, exception: " << e.what() << endl;
}

catch (...) {
	cerr << "cerr everything else exception\n";
}