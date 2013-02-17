#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

struct TextBox : Shape {
    TextBox(Point xxyy, int ww, int hh, string ss) : xy(xxyy), w(ww), h(hh), text(ss) {
        if (w <= 0) error("Width must be greater than 0.");
        if (h <= 0) error("Height must be greater than 0.");
    }

    void draw_lines() const;

    Point point() const {
        return xy;
    }

    int width() const {return w;}
    int height() const {return h;}

private:
    Point xy;
    int w, h;
    string text;
};


Graph_lib::Line connect(const TextBox& from, const TextBox& to) {
    int from_x, from_y;
    int to_x, to_y;

    if (from.point().y + from.height()/2 == to.point().y + to.height()/2) {
        from_x = from.point().x + (from.point().x < to.point().x ? from.width() : 0);
        from_y = from.point().y + from.height()/2;
        
        to_x = to.point().x + (from.point().x < to.point().x ? 0 : to.width());
        to_y = to.point().y + to.height()/2;

        printf("%d, %d, %d, %d\n", from_x, from_y, to_x, to_y);
    } else {
        from_x = from.point().x + from.width()/2;
        from_y = (from.point().y + (from.height() < to.point().y) ? from.point().y + from.height() : from.point().y);
        
        to_x = to.point().x + to.width()/2;
        to_y = from.point().y < to.point().y ? to.point().y : to.point().y + to.height();
    }

    return Graph_lib::Line(Point(from_x, from_y), Point(to_x, to_y));
}

void TextBox::draw_lines() const {
    fl_rect(xy.x, xy.y, w, h);

    if (text.size() > 0) {
        int ofnt = fl_font();
        int osz = fl_size();
        fl_draw(text.c_str(),xy.x + 20, xy.y + h/2);
        fl_font(ofnt,osz);
    }
}

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 800, 800, "Window");

    TextBox a(Point(30, 40), 300, 50, "more text, like, a LOT more");
    TextBox b(Point(200, 200), 100, 200, "box");

    Graph_lib::Line l = connect(a, b);

    TextBox c(Point(400, 100), 40, 100, "ewrr");
    TextBox d(Point(550, 120), 200, 100, "box");

    Graph_lib::Line l1 = connect(a, b);
    Graph_lib::Line l2 = connect(d, c);

    win.attach(a);
    win.attach(b);
    win.attach(c);
    win.attach(d);
    win.attach(l1);
    win.attach(l2);


    win.wait_for_button();

    return 0;
}

