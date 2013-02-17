#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(100, 100), x_max()*0.8, y_max()*0.9, "Cat program");

    Graph_lib::Polygon triangle;
    triangle.add(Point(300, 300));
    triangle.add(Point(350, 300 - sqrt(100*100 - 50*50)));
    triangle.add(Point(400, 300));

    Graph_lib::Rectangle rect(Point(300, 300 - sqrt(100*100 - 50*50)), 100, 100);

    win.attach(triangle);
    win.attach(rect);

    win.wait_for_button();

    return 0;
}
