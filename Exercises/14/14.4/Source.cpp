#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

using namespace Graph_lib;

class ImmovableCircle : public Graph_lib::Circle {
public:
    ImmovableCircle(Point cc, int rr) : Graph_lib::Circle(cc, rr) {}

    void move(int dx, int dy) {};
};

int main(){
    Simple_window win(Point(200, 200), 800, 500, "Window");

    ImmovableCircle s(Point(50, 50), 50);

    win.attach(s);

    s.move(300, 200);

    win.wait_for_button();
    return 0;
}