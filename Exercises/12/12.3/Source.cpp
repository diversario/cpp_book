#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 640, 480, "Window");

    Text t1(Point(20, 400), "I");
    t1.set_font_size(150);
    t1.set_font(Font::courier_bold);
    t1.set_color(Color::dark_magenta);

    Text t2(Point(200, 400), "S");
    t2.set_font_size(150);
    t2.set_font(Font::courier_bold);
    t2.set_color(Color::white);

    win.attach(t1);
    win.attach(t2);

    win.wait_for_button();

    return 0;
}
