#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

using namespace Graph_lib;

struct Lines_window : Window {
    Lines_window(Point xy, int w, int h, const string& title);
private:
    Graph_lib::Open_polyline lines;
    Menu color_menu;
    Button menu_button;
    Menu style_menu;
    Button style_button;

    void red_pressed() {change(Color::red); hide_menu();}
    void blue_pressed() {change(Color::blue); hide_menu();}
    void black_pressed() {change(Color::black); hide_menu();}
    void dash_pressed() {change_style(Line_style(Line_style::dash, 1)); hide_style_menu();}
    void menu_pressed() {menu_button.hide(); color_menu.show();}
    void style_button_pressed() {style_button.hide(); style_menu.show();}

    void change(Color c) {lines.set_color(c); redraw();}
    void change_style(Line_style l) {lines.set_style(l); redraw();}
    void hide_menu() {color_menu.hide(); menu_button.show();}
    void hide_style_menu() {style_menu.hide(); style_button.show();}

    void next();
    void quit();

    Button next_button;
    Button quit_button;
    In_box next_x;
    In_box next_y;
    Out_box xy_out;

    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_style_button(Address, Address);
    static void cb_dash(Address, Address);
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    : Window(xy, w, h, title),
    next_button(Point(x_max() - 150, 0), 70, 20, "Next point", cb_next),
    quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
    next_x(Point(x_max() - 310, 0), 50, 20, "next x:"),
    next_y(Point(x_max() - 210, 0), 50, 20, "next y:"),
    xy_out(Point(100, 0), 100, 20, "current x,y:"),
    color_menu(Point(x_max() - 70, 40), 70, 20, Menu::vertical, "color"),
    menu_button(Point(x_max() - 80, 30), 80, 20, "color menu", cb_menu),
    style_menu(Point(x_max() - 110, 40), 70, 20, Menu::vertical, "style"),
    style_button(Point(x_max() - 110, 30), 80, 20, "style menu", cb_style_button)
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    color_menu.attach(new Button(Point(0, 0), 0, 0, "red", cb_red));
    color_menu.attach(new Button(Point(0, 0), 0, 0, "blue", cb_blue));
    color_menu.attach(new Button(Point(0, 0), 0, 0, "black", cb_black));
    attach(color_menu);
    attach(menu_button);
    
    style_menu.attach(new Button(Point(0, 0), 0, 0, "dash", cb_dash));
    attach(style_menu);
    attach(style_button);

    attach(lines);

    color_menu.hide();
    style_menu.hide();
}

void Lines_window::cb_quit(Address, Address pw) {
    reference_to<Lines_window>(pw).quit();
}

void Lines_window::cb_next(Address, Address pw) {
    reference_to<Lines_window>(pw).next();
}

void Lines_window::cb_menu(Address, Address pw) {
    reference_to<Lines_window>(pw).menu_pressed();
}

void Lines_window::cb_style_button(Address, Address pw) {
    reference_to<Lines_window>(pw).style_button_pressed();
}

void Lines_window::cb_dash(Address, Address pw) {
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_red(Address, Address pw) {
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw) {
    reference_to<Lines_window>(pw).blue_pressed();
}

void Lines_window::cb_black(Address, Address pw) {
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::quit() {
    hide();
}

void Lines_window::next() {
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point(x, y));
    
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

int main() {
    Lines_window win(Point(100, 100), 600, 400, "Lines");
    return gui_main();
}