#include "../../../Includes/Simple_window.h"
#include "../../../Includes/Graph.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(100, 100), 800, 600, "Some window");

    Axis xa(Axis::x, Point(20, 400), 280, 10, "x axis");
    Axis ya(Axis::y, Point(20, 400), 280, 10, "y axis");
    
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);

    Function sine(sin, 0, 100, Point(20, 200), 1000, 50, 50);
    sine.set_color(Color::blue);

    Graph_lib::Polygon poly;
    poly.add(Point(300, 200));
    poly.add(Point(350, 100));
    poly.add(Point(400, 200));

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    poly.set_style(Line_style(Line_style::dash, 4));

    Graph_lib::Rectangle r(Point(200, 200), 100, 50);
    r.set_fill_color(Color::dark_cyan);

    Closed_polyline poly_rect;
    poly_rect.add(Point(100, 50));
    poly_rect.add(Point(200, 50));
    poly_rect.add(Point(200, 100));
    poly_rect.add(Point(100, 100));
    poly_rect.add(Point(50, 75));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);

    Graph_lib::Text t(Point(300, 300), "FUCK YEAH graphics wooo");
    t.set_font(Font::helvetica_bold);
    t.set_font_size(30);

    Image ii(Point(600, 450), "image1.jpg");

    Circle c(Point(100, 200), 50);

    Graph_lib::Ellipse e(Point(100, 200), 75, 25);
    e.set_color(Color::dark_red);

    Mark m(Point(100, 200), 'x');

    ostringstream oss;

    oss << "screen size: " << Graph_lib::x_max() << 'x' << Graph_lib::y_max()
        << "; window size: " << win.x_max() << 'x' << win.y_max() << '.';

    Graph_lib::Text sizes(Point(100, 20), oss.str());

    Image cat(Point(40, 40), "image1.jpg");
    cat.set_mask(Point(150, 220), 200, 200);

    win.attach(xa);
    win.attach(ya);
    win.attach(sine);
    win.attach(poly);
    win.attach(r);
    win.attach(poly_rect);
    win.attach(t);
    win.attach(ii);
    win.attach(c);
    win.attach(e);
    win.attach(m);
    win.attach(sizes);
    win.attach(cat);

    win.set_label("Window!");

    win.wait_for_button();
    return 0;
}