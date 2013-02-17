#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

using namespace Graph_lib;

const double PI = atan(1) * 4;

class StripedCircle : public Graph_lib::Circle {
public:
    StripedCircle(Point pp, int rr): Graph_lib::Circle(pp, rr) {}

    void draw_lines() const;
};

void StripedCircle::draw_lines() const {
    Graph_lib::Circle::draw_lines();
    
    double step = 180 / (float)radius()*2,
        a = 0;

    for (int i=4; i<radius()*2; i+=4) {
        a += step;
        double y = center().y - radius() * sin((a) * PI/180);
        fl_line(center().x - radius() + i, y, center().x - radius() + i, y + (center().y - y)*2 - 1);
    }
}

int main(){
    Simple_window win(Point(200, 200), 800, 500, "Window");

    StripedCircle s(Point(200, 200), 100);

    win.attach(s);

    win.wait_for_button();
    return 0;
}