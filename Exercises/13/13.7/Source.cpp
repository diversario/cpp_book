#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 800, 800, "Window");

    Vector_ref<Graph_lib::Rectangle> tiles;

    for (int i=0; i<16; i++) {
        for (int j=0; j<16; j++) {
            tiles.push_back(new Graph_lib::Rectangle(Point(i*30, j*30), 30, 30));
            tiles[tiles.size()-1].set_fill_color(Color(i*16 + j));
            tiles[tiles.size()-1].set_color(Color::Transparency::invisible);
            win.attach(tiles[tiles.size()-1]);
        }
    }

    win.wait_for_button();

    return 0;
}

