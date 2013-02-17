#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 640, 480, "Window");

    Graph_lib::Rectangle rect(Point(20, 20), 100, 400);
    rect.set_color(Color::red);

    Graph_lib::Polygon poly;
    poly.add(Point(100, 100));
    poly.add(Point(200, 100));
    poly.add(Point(200, 150));
    poly.add(Point(100, 150));
    poly.set_color(Color::blue);

    win.attach(rect);
    win.attach(poly);

    win.wait_for_button();

    return 0;
}
