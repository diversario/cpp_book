#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(100, 100), x_max()*0.8, y_max()*0.9, "Cat program");

    Graph_lib::Image img(Point(100, 100), "image1.jpg");
    Text txt(Point(130, 80), "Kitty!");

    win.attach(img);
    win.attach(txt);

    win.wait_for_button();

    return 0;
}
