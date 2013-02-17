#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

using namespace Graph_lib;

const double PI = atan(1) * 4;

class Octagon : public Graph_lib::Shape {
public:
    Octagon(Point pp, int rr): center(pp), radius(rr) {
        int angle = 45;
    }

    void draw_lines() const;
private:
    Point center;
    int radius, angle;
};

void Octagon::draw_lines() const {
    double angle = 45 * PI/180;
}

int main(){
    Simple_window win(Point(200, 200), 800, 500, "Window");

    StripedCircle s(Point(200, 200), 100);

    win.attach(s);

    win.wait_for_button();
    return 0;
}