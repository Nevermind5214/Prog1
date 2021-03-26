/*
g++ Ch12Ex1-9.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Ch12Ex1-9 `fltk-config --ldflags --use-images`
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

	// 1. Draw a rectangle as a Rectangle and as a Polygon . Make the lines of the
	// Polygon red and the lines of the Rectangle blue.
	Rectangle r {Point{100,100}, 100, 50};
	r.set_color(Color::red);
	win.attach(r);

	Polygon polyrect;
	polyrect.add(Point{210,100});
	polyrect.add(Point{310,100});
	polyrect.add(Point{310,150});
	polyrect.add(Point{210,150});

	polyrect.set_color(Color::blue);
	win.attach(polyrect);

	// 2. Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.
	Rectangle howdyrect {Point{100,55}, 100, 30};
	Text howdytext {Point{125,75}, "Howdy"};
	win.attach(howdyrect);
	win.attach(howdytext);

	// 3. Draw your initials 150 pixels high. Use a thick line. Draw each initial in
	// a different color.
	Text initm {Point{200,340}, "M"};
	initm.set_font_size(150);
	initm.set_color(Color::blue);
	win.attach(initm);

	Text initd {Point{315,340}, "D"};
	initd.set_font_size(150);
	initd.set_color(Color::red);
	win.attach(initd);

	// 4. Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
	Rectangle r1 {Point{350,100}, 20, 20};
	Rectangle r2 {Point{372,100}, 20, 20};
	Rectangle r3 {Point{394,100}, 20, 20};
	Rectangle r4 {Point{350,122}, 20, 20};
	Rectangle r5 {Point{372,122}, 20, 20};
	Rectangle r6 {Point{394,122}, 20, 20};
	Rectangle r7 {Point{350,144}, 20, 20};
	Rectangle r8 {Point{372,144}, 20, 20};
	Rectangle r9 {Point{394,144}, 20, 20};
	r1.set_color(Color::white);
	r2.set_color(Color::red);
	r3.set_color(Color::white);
	r4.set_color(Color::red);
	r5.set_color(Color::white);
	r6.set_color(Color::red);
	r7.set_color(Color::white);
	r8.set_color(Color::red);
	r9.set_color(Color::white);
	win.attach(r1);
	win.attach(r2);
	win.attach(r3);
	win.attach(r4);
	win.attach(r5);
	win.attach(r6);
	win.attach(r7);
	win.attach(r8);
	win.attach(r9);

	// 5. Draw a red 1⁄4-inch frame around a rectangle that is three-quarters the
	// height of your screen and two-thirds the width

	Rectangle rect5 {Point{xmax/8,ymax/8}, xmax*3/4, ymax*3/4};
	win.attach(rect5);
	// Display size: 19.17" × 10.79" = 206.81in² (48.7cm × 27.4cm = 1334.28cm²) at 100.13 PPI
	// 1 inch ~ 100px
	Rectangle rectinch {Point{xmax/8-25,ymax/8-25}, xmax*3/4+50, ymax*3/4+50};
	win.attach(rectinch);

	// 7. . Draw a two-dimensional house seen from the front, the way a child
	// would: with a door, two windows, and a roof with a chimney. Feel free to
	// add details; maybe have “smoke” come out of the chimney.
	Polygon polyteto;
	polyteto.add(Point{100,200});
	polyteto.add(Point{200,200});
	polyteto.add(Point{150,150});
	win.attach(polyteto);

	Rectangle rectfalak {Point{115,200}, 70, 70};
	win.attach(rectfalak);

	Rectangle rectajto {Point{140,230}, 20, 40};
	win.attach(rectajto);

	Rectangle rectablak1 {Point{120,210}, 15, 15};
	win.attach(rectablak1);

	Rectangle rectablak2 {Point{165,210}, 15, 15};
	win.attach(rectablak2);

	Open_polyline polykemeny;

	polykemeny.add(Point{125,175});
	polykemeny.add(Point{125,155});
	polykemeny.add(Point{135,155});
	polykemeny.add(Point{135,165});
	win.attach(polykemeny);

	// 8. Draw the Olympic five rings. If you can’t remember the colors, look them up.
	Circle c1 {Point{403,200},20};
	c1.set_color(Color::blue);
	win.attach(c1);

	Circle c2 {Point{445,200},20};
	c2.set_color(Color::black);
	win.attach(c2);

	Circle c3 {Point{487,200},20};
	c3.set_color(Color::red);
	win.attach(c3);

	Circle c4 {Point{423,220},20};
	c4.set_color(Color::yellow);
	win.attach(c4);

	Circle c5 {Point{467,220},20};
	c5.set_color(Color::green);
	win.attach(c5);

	// 9. Display an image on the screen, e.g., a photo of a friend. Label the image
	// both with a title on the window and with a caption in the window.
	Simple_window fren {tl,200,250,"Photo of a friend"};
	Image photooffriend {Point(0,20),"image.jpg"};
	fren.attach(photooffriend);
	Text frencapt {Point{15,245}, "Photo of a friend"};
	frencapt.set_font_size(20);
	fren.attach(frencapt);
	fren.wait_for_button(); 

	//6. What happens when you draw a Shape that doesn’t fit inside its window?
	// What happens when you draw a Window that doesn’t fit on your screen?
	Ellipse e {Point{0, 0}, xmax+10, ymax+10};
	win.attach(e);

	win.wait_for_button(); // give control to the display engine

	Simple_window bigwin {tl,3000,3000,"toobigomg"}; // make a simple window
	bigwin.wait_for_button(); 

}

catch (exception& e) {
	cerr << "Oopsie doopsie wtf happened, exception: " << e.what() << endl;
}

catch (...) {
	cerr << "cerr everything else exception\n";
}