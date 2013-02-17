#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(100, 100), x_max()*0.8, y_max()*0.9, "Window");

    Point top_left_wall(100, 400);

    Graph_lib::Rectangle wall(top_left_wall, 300, 300);
    wall.set_fill_color(Color::dark_red);

    Graph_lib::Rectangle window1(Point(120, 450), 100, 150);
    window1.set_fill_color(Color::yellow);

    Graph_lib::Rectangle window2(Point(290, 450), 100, 150);
    window2.set_fill_color(Color::yellow);

    Graph_lib::Closed_polyline roof;
    roof.add(top_left_wall);
    roof.add(Point(250, 200));
    roof.add(Point(400, 400));
    roof.set_fill_color(Color::dark_blue);

    Graph_lib::Closed_polyline chimney;
    chimney.add(Point(300, 267));
    chimney.add(Point(300, 200));
    chimney.add(Point(350, 200));
    chimney.add(Point(350, 333));
    chimney.set_fill_color(Color::dark_yellow);

    Graph_lib::Circle smoke1(Point(320, 180), 10);
    smoke1.set_fill_color(Color::cyan);
    
    Graph_lib::Circle smoke2(Point(340, 160), 20);
    smoke2.set_fill_color(Color::cyan);

    Graph_lib::Circle smoke3(Point(330, 130), 30);
    smoke3.set_fill_color(Color::cyan);

    win.attach(wall);
    win.attach(window1);
    win.attach(window2);
    win.attach(roof);
    win.attach(chimney);
    win.attach(smoke1);
    win.attach(smoke2);
    win.attach(smoke3);

    win.wait_for_button();

    return 0;
}
