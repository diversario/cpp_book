#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

using namespace Graph_lib;

class StripedRect : public Graph_lib::Rectangle {
public:
    StripedRect(Point pp, int ww, int hh): Graph_lib::Rectangle(pp, ww, hh) {}

    void draw_lines() const;
};

void StripedRect::draw_lines() const {
    Graph_lib::Rectangle::draw_lines();

    for (int i=4; i<width(); i+=4) {
        fl_line(point(0).x + i, point(0).y, point(0).x + i, point(0).y + height() - 1);
    }
}

int main(){
    Simple_window win(Point(200, 200), 800, 500, "Window");

    StripedRect s(Point(100, 100), 400, 200);

    win.attach(s);

    win.wait_for_button();
    return 0;
}