#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"


struct RoundedBox : Graph_lib::Shape {
    Point corner;

    RoundedBox(Point c, int ww, int hh, int rr): width(ww), height(hh), radius(rr) {
        corner.x = c.x;
        corner.y = c.y;
    }

    void draw_lines() const;

private:
    int width, height, radius;
};

void RoundedBox::draw_lines() const {
    fl_line(corner.x + radius, corner.y, corner.x + width - radius, corner.y);
    fl_line(corner.x + width, corner.y + radius, corner.x + width, corner.y + height - radius);
    fl_line(corner.x + radius, corner.y + height, corner.x + width - radius, corner.y + height);
    fl_line(corner.x, corner.y - radius + height, corner.x, corner.y + radius);

    fl_arc(corner.x, corner.y, radius*2, radius*2, 90, 180);
    fl_arc(corner.x + width - radius*2, corner.y, radius*2, radius*2, 0, 90);
    fl_arc(corner.x + width - radius*2, corner.y + height - radius*2, radius*2, radius*2, 270, 0);
    fl_arc(corner.x, corner.y + height - radius*2, radius*2, radius*2, 180, 270);
}

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 800, 800, "Window");

    RoundedBox a(Point(50, 50), 300, 300, 50);
    RoundedBox b(Point(400, 400), 300, 100, 5);

    win.attach(a);
    win.attach(b);

    win.wait_for_button();

    return 0;
}

