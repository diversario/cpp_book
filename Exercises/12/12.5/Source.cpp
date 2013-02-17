#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(100, 100), x_max()*0.8, y_max()*0.9, "Window");

    Graph_lib::Rectangle r(Point(50, 50), x_max()*0.667, y_max()*0.75);
    r.set_style(Line_style(Line_style::solid, 4));
    r.set_color(Color::red);

    win.attach(r);

    win.wait_for_button();

    return 0;
}
