#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(100, 100), x_max()*0.8, y_max()*0.9, "Window");

    Graph_lib::Circle c1(Point(200, 200), 70);
    c1.set_color(Color::blue);
    c1.set_style(Line_style(Line_style::solid, 4));

    Graph_lib::Circle c2(Point(300, 200), 70);
    c2.set_color(Color::black);
    c2.set_style(Line_style(Line_style::solid, 4));

    Graph_lib::Circle c3(Point(400, 200), 70);
    c3.set_color(Color::red);
    c3.set_style(Line_style(Line_style::solid, 4));

    Graph_lib::Circle c4(Point(250, 300), 70);
    c4.set_color(Color::yellow);
    c4.set_style(Line_style(Line_style::solid, 4));

    Graph_lib::Circle c5(Point(350, 300), 70);
    c5.set_color(Color::green);
    c5.set_style(Line_style(Line_style::solid, 4));

    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(c4);
    win.attach(c5);

    win.wait_for_button();

    return 0;
}
