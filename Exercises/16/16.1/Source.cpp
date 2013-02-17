#include "../../../Includes/GUI.h"
#include "../../../Includes/Window.h"

using namespace Graph_lib;

class Not_so_simple_window : public Window {
public:
    Not_so_simple_window(Point _xy, int ww, int hh, const string& title);
    void wait_for_button();
private:
    Button next_button;
    Button quit_button;
    bool next_pressed;

    void next() {next_pressed = false;}
    void quit() {hide();}

    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
};

Not_so_simple_window::Not_so_simple_window(Point _xy, int ww, int hh, const string& title)
    : Window(_xy, ww, hh, title),
    next_pressed(false),
    next_button(Point(x_max() - 150, 0), 70, 20, "Next", cb_next),
    quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit)
{
    attach(next_button);
    attach(quit_button);
}

void Not_so_simple_window::cb_next(Address, Address pw) {
    reference_to<Not_so_simple_window>(pw).next();
}

void Not_so_simple_window::cb_quit(Address, Address pw) {
    reference_to<Not_so_simple_window>(pw).quit();
}

void Not_so_simple_window::wait_for_button() {
    while(!next_pressed) Fl::wait();
    next_pressed = false;
    Fl::redraw();
}

int main(){
    Not_so_simple_window ns(Point(200, 200), 400, 600, "Win!");
    ns.wait_for_button();
}
