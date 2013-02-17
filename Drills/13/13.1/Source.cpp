#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(50, 50), 1000, 800, "Window");

    Lines grid;
    Vector_ref<Graph_lib::Rectangle> squares;

    int unit = 100;

    for (int i = unit; i <= 800; i += unit) {
        grid.add(Point(i, 0), Point(i, win.y_max()));
        grid.add(Point(0, i), Point(800, i));

        squares.push_back(new Graph_lib::Rectangle(Point(i-unit, i-unit), unit, unit));
        squares[squares.size()-1].set_fill_color(Color::red);
        squares[squares.size()-1].set_color(Color::Transparency::invisible);

        win.attach(squares[squares.size()-1]);
    }
    win.attach(grid);

    while(1) {
        int x = (rand() % 6)*100,
            y = (rand() % 6)*100;

        Graph_lib::Image img1(Point(x, y), (string("image.jpg")).c_str());
        win.attach(img1);
        win.wait_for_button();
    }

    return 0;
}