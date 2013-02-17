#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

double a = 300,
    b = 300,
    n = 2,
    offset = 100;

const double PI = atan(1) * 4;

double getX(double theta) {
    return a * pow(cos(theta), 2*n);
}

double getY(double theta) {
    return b * pow(sin(theta), 2*n);
}

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(100, 100), 800, 800, "I LOVE CATS");

    Graph_lib::Open_polyline shape1;
    Graph_lib::Open_polyline shape2;
    Graph_lib::Open_polyline shape3;
    Graph_lib::Open_polyline shape4;

    Graph_lib::Circle circle(Point(400, 400), 300);

    for (int i=0; i<=90; i += 1) {
        double theta = i * PI/180;
        shape1.add(Point(getX(theta) + offset, getY(theta) + offset));
        shape2.add(Point(getX(theta) + (a - getX(theta))*2 + offset, getY(theta) + offset));
        shape3.add(Point(getX(theta) + offset, getY(theta) + (b - getY(theta))*2 + offset));
        shape4.add(Point(getX(theta) + (a - getX(theta))*2 + offset, getY(theta) + (b - getY(theta))*2 + offset));
    }

    shape1.set_style(Line_style(Line_style::solid, 3));
    shape1.set_color(Color::red);

    shape2.set_style(Line_style(Line_style::solid, 3));
    shape2.set_color(Color::blue);

    shape3.set_style(Line_style(Line_style::solid, 3));
    shape3.set_color(Color::dark_green);

    shape4.set_style(Line_style(Line_style::solid, 3));
    shape4.set_color(Color::magenta);

    win.attach(shape1);
    win.attach(shape2);
    win.attach(shape3);
    win.attach(shape4);

    //win.attach(circle);

    win.wait_for_button();

    return 0;
}
