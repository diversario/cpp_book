#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(100, 100), x_max()*0.8, y_max()*0.9, "Cat program");

    Text pointhlabel(Point(100, 100), "Point.h");
    pointhlabel.set_font(Font::courier_bold);
    Graph_lib::Rectangle pointhbox(Point(100, 110), 200, 40);
    pointhbox.set_fill_color(Color::yellow);
    Text pointhtext(Point(105, 135), "struct Point {...};");

    win.attach(pointhlabel); win.attach(pointhbox); win.attach(pointhtext);

    Text graphhlabel(Point(100, 200), "Graph.h");
    graphhlabel.set_font(Font::courier_bold);
    Graph_lib::Rectangle graphhbox(Point(100, 210), 200, 40);
    graphhbox.set_fill_color(Color::yellow);
    Text graphhtext1(Point(105, 225), "//graphics interface");
    Text graphhtext2(Point(105, 240), "struct Shape {...};");

    win.attach(graphhlabel); win.attach(graphhbox); win.attach(graphhtext1); win.attach(graphhtext2);

    win.wait_for_button();

    return 0;
}
