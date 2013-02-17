#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"


Point e(Graph_lib::Rectangle& r) {
    int x = r.point(0).x,
        y = r.point(0).y;

    Point e(x, y + r.height()/2);

    return e;
}

Point ne(Graph_lib::Rectangle& r) {
    int x = r.point(0).x,
        y = r.point(0).y;

    Point e(x, y);

    return e;
}

Point n(Graph_lib::Rectangle& r) {
    int x = r.point(0).x,
        y = r.point(0).y;

    Point e(x + r.width()/2, y);

    return e;
}


Point nw(Graph_lib::Rectangle& r) {
    int x = r.point(0).x,
        y = r.point(0).y;

    Point e(x + r.width(), y);

    return e;
}


Point w(Graph_lib::Rectangle& r) {
    int x = r.point(0).x,
        y = r.point(0).y;

    Point e(x + r.width(), y + r.height()/2);

    return e;
}

Point sw(Graph_lib::Rectangle& r) {
    int x = r.point(0).x,
        y = r.point(0).y;

    Point e(x + r.width(), y + r.height());

    return e;
}

Point s(Graph_lib::Rectangle& r) {
    int x = r.point(0).x,
        y = r.point(0).y;

    Point e(x + r.width()/2, y + r.height());

    return e;
}

Point se(Graph_lib::Rectangle& r) {
    int x = r.point(0).x,
        y = r.point(0).y;

    Point e(x, y + r.height());

    return e;
}


int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 800, 800, "Window");

    Graph_lib::Rectangle r(Point(10, 10), Point(333, 501));

    Point east = e(r);
    Point neast = ne(r);
    Point north = n(r);
    Point nwest = nw(r);
    Point west = w(r);
    Point swest = sw(r);
    Point south = s(r);
    Point seast = se(r);

    Mark m1(east, '1');
    Mark m2(neast, '2');
    Mark m3(north, '3');
    Mark m4(nwest, '4');
    Mark m5(west, '5');
    Mark m6(swest, '6');
    Mark m7(south, '7');
    Mark m8(seast, '8');

    win.attach(r);
    win.attach(m1);
    win.attach(m2);
    win.attach(m3);
    win.attach(m4);
    win.attach(m5);
    win.attach(m6);
    win.attach(m7);
    win.attach(m8);

    win.wait_for_button();

    return 0;
}

