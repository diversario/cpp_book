#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

using namespace Graph_lib;

class Controller {
public:
    Controller(int l, bool st): level(l), state(st) {}

    virtual void on() {state = true;}
    virtual void off() {state = false;}
    virtual void show() {cout << "Controller: level " << level << ", state " << state;};
    virtual void setLevel(int l) {level = l;}

protected:
    int level;
    bool state;
};


class Test : public Controller {
public:
    Test(int l, bool st): Controller(l, st) {}

    void show() const;
};

void Test::show() const {
    std::cout << state << ", " << level << endl;
}

class ShapeControl : public Controller {
public:
    ShapeControl(Shape& ss): s(ss), Controller(0, false) {}

    void setLevel(int);
private:
    Shape& s;
};

void ShapeControl::setLevel(int l) {
    Controller::setLevel(l);
    s.set_style(Line_style(Line_style::dash, level));
}

int main(){
    Simple_window win(Point(200, 200), 400, 400, "Window");

    Circle c(Point(200, 200), 75);
    ShapeControl sc(c);

    sc.setLevel(1);

    win.attach(c);

    win.wait_for_button();
    //keep_window_open();
    return 0;
}