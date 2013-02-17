#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

using namespace Graph_lib;

class Smiley : public Graph_lib::Circle {
public:
    Smiley(Point cc, int rr) : Graph_lib::Circle(cc, rr) {}

    void draw_lines() const;
};

void Smiley::draw_lines() const {
    Graph_lib::Circle::draw_lines();

    int left_eye_center_x = center().x - radius()/2.5;
    int left_eye_center_y = center().y - radius()/2.5;

    fl_circle(left_eye_center_x, left_eye_center_y, radius()/4);

    int right_eye_center_x = center().x + radius()/2.5;
    int right_eye_center_y = center().y - radius()/2.5;

    fl_circle(right_eye_center_x, right_eye_center_y, radius()/4);

    fl_arc(center().x - radius()/4 , center().y, radius()/2, radius()/3, 200, 300);
}

class Frowney : public Graph_lib::Circle {
public:
    Frowney(Point cc, int rr) : Graph_lib::Circle(cc, rr) {

    }

    void draw_lines() const;
};

void Frowney::draw_lines() const {
    Graph_lib::Circle::draw_lines();
    
    int left_eye_center_x = center().x - radius()/2.5;
    int left_eye_center_y = center().y - radius()/2.5;

    fl_circle(left_eye_center_x, left_eye_center_y, radius()/4);

    int right_eye_center_x = center().x + radius()/2.5;
    int right_eye_center_y = center().y - radius()/2.5;

    fl_circle(right_eye_center_x, right_eye_center_y, radius()/4);

    fl_arc(center().x - radius()/4 , center().y, radius()/2, radius()/3, 20, 160);
}


class SmileyHat : public Smiley {
public:
    SmileyHat(Point pp, int rr): Smiley(pp, rr) {}  

    void draw_lines() const;
};

void SmileyHat::draw_lines() const {
    fl_circle(center().x, center().y - radius(), 20);
    Smiley::draw_lines();
}

int main(){
    Simple_window win(Point(200, 200), 800, 800, "Window");

    SmileyHat s(Point(200, 200), 100);
    Frowney f(Point(400, 400), 100);

    win.attach(s);
    win.attach(f);

    win.wait_for_button();
    return 0;
}