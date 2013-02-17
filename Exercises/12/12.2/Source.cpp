#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 640, 480, "Window");

    Graph_lib::Rectangle rect(Point(20, 20), 100, 30);
    rect.set_color(Color::red);

    Text t(Point(30, 40), "Howdy!");

    win.attach(rect);
    win.attach(t);

    win.wait_for_button();

    return 0;
}
