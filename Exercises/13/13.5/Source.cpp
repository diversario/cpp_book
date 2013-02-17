#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

const double PI = atan(1)*4;

Point getPoint(Graph_lib::Ellipse& e, int ang) {
    double angle = ang * PI/180;
    double major = e.major() > e.minor() ? e.major() : e.minor();
    double minor = e.major() > e.minor() ? e.minor() : e.major();

    double x = e.center().x + minor * cos(angle);
    double y = e.center().y + major * sin(angle);

    return Point(x, y);
}

Point getPoint(Graph_lib::Circle& c, int ang) {
    double angle = ang * PI/180;
    
    double x = c.center().x + c.radius() * cos(angle);
    double y = c.center().y + c.radius() * sin(angle);

    return Point(x, y);
}

Point e(Graph_lib::Circle& s) { return getPoint(s, 180); }
Point ne(Graph_lib::Circle& s) { return getPoint(s, 135); }
Point n(Graph_lib::Circle& s) { return getPoint(s, 90); }
Point nw(Graph_lib::Circle& s) { return getPoint(s, 45); }
Point w(Graph_lib::Circle& s) { return getPoint(s, 0); }
Point sw(Graph_lib::Circle& s) { return getPoint(s, 315); }
Point s(Graph_lib::Circle& s) { return getPoint(s, 270); }
Point se(Graph_lib::Circle& s) { return getPoint(s, 225); }

Point e(Graph_lib::Ellipse& s) { return getPoint(s, 180); }
Point ne(Graph_lib::Ellipse& s) { return getPoint(s, 135); }
Point n(Graph_lib::Ellipse& s) { return getPoint(s, 90); }
Point nw(Graph_lib::Ellipse& s) { return getPoint(s, 45); }
Point w(Graph_lib::Ellipse& s) { return getPoint(s, 0); }
Point sw(Graph_lib::Ellipse& s) { return getPoint(s, 315); }
Point s(Graph_lib::Ellipse& s) { return getPoint(s, 270); }
Point se(Graph_lib::Ellipse& s) { return getPoint(s, 225); }

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 800, 800, "Window");

    //Graph_lib::Rectangle r(Point(10, 10), Point(333, 501));
    Graph_lib::Ellipse ellipse(Point(200, 200), 100, 170);
    Graph_lib::Circle  circle(Point(400, 500), 200);

    win.attach(ellipse);
    win.attach(circle);

    Point east1 = e(ellipse);
    Point neast1 = ne(ellipse);
    Point north1 = n(ellipse);
    Point nwest1 = nw(ellipse);
    Point west1 = w(ellipse);
    Point swest1 = sw(ellipse);
    Point south1 = s(ellipse);
    Point seast1 = se(ellipse);

    Mark m1(east1, '1');
    Mark m2(neast1, '2');
    Mark m3(north1, '3');
    Mark m4(nwest1, '4');
    Mark m5(west1, '5');
    Mark m6(swest1, '6');
    Mark m7(south1, '7');
    Mark m8(seast1, '8');

    Point east2 = e(circle);
    Point neast2 = ne(circle);
    Point north2 = n(circle);
    Point nwest2 = nw(circle);
    Point west2 = w(circle);
    Point swest2 = sw(circle);
    Point south2 = s(circle);
    Point seast2 = se(circle);

    Mark m9(east2, '1');
    Mark m10(neast2, '2');
    Mark m11(north2, '3');
    Mark m12(nwest2, '4');
    Mark m13(west2, '5');
    Mark m14(swest2, '6');
    Mark m15(south2, '7');
    Mark m16(seast2, '8');

    win.attach(m1);
    win.attach(m2);
    win.attach(m3);
    win.attach(m4);
    win.attach(m5);
    win.attach(m6);
    win.attach(m7);
    win.attach(m8);

    win.attach(m9);
    win.attach(m10);
    win.attach(m11);
    win.attach(m12);
    win.attach(m13);
    win.attach(m14);
    win.attach(m15);
    win.attach(m16);

    win.wait_for_button();

    return 0;
}

