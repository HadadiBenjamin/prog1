#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{1,1}, xmax, ymax, "window"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 50;
	int ylength = ymax - 50;

	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function cos_func ( [] (double x) { return cos(x); },
						rmin, rmax, origo, n_points, xscale, yscale);

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle r {Point{200,200}, 100, 50};

	r.set_fill_color(Color::dark_green);
	r.set_style(Line_style(Line_style::solid, 4));

	Text t {Point{200,400}, "Hello graphics!"};
	t.set_font(Font::times_bold_italic);
	t.set_font_size(90);

	Image ii {Point{100,100}, "badge.jpg"};
        
        Text p {Point{700,600}, "New message!"};
	t.set_font(Font::helvetica);
	t.set_font_size(60);


	Circle c {Point{700,700}, 100};

	Ellipse e {Point{500,500}, 100, 50};
	e.set_fill_color(Color::yellow);

	win.attach(e);
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(s);
	win.attach(sq);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);
        win.attach(p);
        
    win.wait_for_button();

}
