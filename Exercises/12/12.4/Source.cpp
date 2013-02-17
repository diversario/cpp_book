#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 640, 480, "Window");

    Point p1(100, 100);
    Graph_lib::Rectangle r1(p1, 100, 100);
    r1.set_fill_color(Color::white);

    Point p2(205, 100);
    Graph_lib::Rectangle r2(p2, 100, 100);
    r2.set_fill_color(Color::red);

    Point p3(310, 100);
    Graph_lib::Rectangle r3(p3, 100, 100);
    r3.set_fill_color(Color::white);


    Point p4(100, 205);
    Graph_lib::Rectangle r4(p4, 100, 100);
    r4.set_fill_color(Color::red);

    Point p5(205, 205);
    Graph_lib::Rectangle r5(p5, 100, 100);
    r5.set_fill_color(Color::white);

    Point p6(310, 205);
    Graph_lib::Rectangle r6(p6, 100, 100);
    r6.set_fill_color(Color::red);


    Point p7(100, 310);
    Graph_lib::Rectangle r7(p7, 100, 100);
    r7.set_fill_color(Color::white);

    Point p8(205, 310);
    Graph_lib::Rectangle r8(p8, 100, 100);
    r8.set_fill_color(Color::red);

    Point p9(310, 310);
    Graph_lib::Rectangle r9(p9, 100, 100);
    r9.set_fill_color(Color::white);


    win.attach(r1);
    win.attach(r2);
    win.attach(r3);
    win.attach(r4);
    win.attach(r5);
    win.attach(r6);
    win.attach(r7);
    win.attach(r8);
    win.attach(r9);

    win.wait_for_button();

    return 0;
}
