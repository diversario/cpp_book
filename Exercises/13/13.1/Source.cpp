#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"


struct MyArc : Graph_lib::Shape {
    Point center;

    MyArc(Point c, int ww, int hh, int _start, int _end): width(ww), height(hh), start(_start), end(_end) {
        center.x = c.x;
        center.y = c.y;
    }

    void draw_lines() const;

private:
    int width, height, start, end;
};

void MyArc::draw_lines() const {
    fl_arc(center.x, center.y, width, height, start, end);
}

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 640, 480, "Window");

    MyArc a(Point(200, 200), 300, 100, 10, 180);
    MyArc b(Point(300, 100), 200, 100, 220, 300);

    win.attach(a);
    win.attach(b);

    win.wait_for_button();

    return 0;
}

