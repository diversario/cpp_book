#include "../../../Includes/Graph.h"
#include "../../../Includes/Simple_window.h"

const double PI = atan(1)*4;

struct Arrow : Graph_lib::Shape {
    Point start;
    Point end;

    Arrow(Point s, Point e) {
        start.x = s.x;
        start.y = s.y;
        end.x = e.x;
        end.y = e.y;
    }

    void draw_lines() const;
};

void Arrow::draw_lines() const {
    fl_line(start.x, start.y, end.x, end.y);

    int ARROW_ANGLE = 30,
        ARROW_LENGTH = 100;

    // end angle between X axis and the line
    double vertical_offset_line = start.y - end.y,
           horizontal_offset_line = end.x - start.x;

    double line_length = sqrt(pow(vertical_offset_line, 2) + pow(horizontal_offset_line, 2)); // hypotenuse

    double angleEX = asin(vertical_offset_line / line_length) * 180.0/PI;

    // angle between arrowhead and X axis
    double angleAX = angleEX - ARROW_ANGLE;
    double horizontal_offset_arrow_1 = sin(180 - 90 - angleAX) * ARROW_LENGTH;
    double vertical_offset_arrow_1 = sin(angleAX) * ARROW_LENGTH;

    double arrow_end_x_1 = end.x + horizontal_offset_arrow_1,
        arrow_end_y_1 = end.y + vertical_offset_arrow_1;

    fl_line(end.x, end.y, arrow_end_x_1, arrow_end_y_1);

    double angleEY = asin(vertical_offset_line / line_length) * 180.0/PI;

    // angle between arrowhead and Y axis
    double angleAY = angleEY - ARROW_ANGLE;
    double vertical_offset_arrow_2 = sin(180 - 90 - angleAY) * ARROW_LENGTH;
    double horizontal_offset_arrow_2 = sin(angleAY) * ARROW_LENGTH;

    double arrow_end_x_2 = end.x - horizontal_offset_arrow_2,
        arrow_end_y_2 = end.y - vertical_offset_arrow_2;

    fl_line(end.x, end.y, arrow_end_x_2, arrow_end_y_2);
    fl_line(arrow_end_x_1, arrow_end_y_1, arrow_end_x_2, arrow_end_y_2);
}

//void Arrow::draw_lines() const {
//    fl_line(start.x, start.y, end.x, end.y);
//
//    int ARROW_ANGLE = 30,
//        ARROW_LENGTH = 100;
//
//    Point start_1(start.x, start.y),
//        end_1(end.x, end.y);
//
//    // end angle between X axis and the line
//    double vertical_offset_line = start_1.y - end_1.y,
//        horizontal_offset_line = end_1.x - start_1.x;
//
//    double line_length = sqrt(pow(vertical_offset_line, 2) + pow(horizontal_offset_line, 2)); // hypotenuse
//
//    double angleEX = asin(vertical_offset_line / line_length) * 180.0/PI;
//
//    // angle between arrowhead and X axis
//    double angleAX = angleEX + ARROW_ANGLE;
//    double horizontal_offset_arrow_1 = sin(180 - 90 - angleAX) * ARROW_LENGTH;
//    double vertical_offset_arrow_1 = sin(angleAX) * ARROW_LENGTH;
//
//    double arrow_end_x_1 = end_1.x - horizontal_offset_arrow_1,
//        arrow_end_y_1 = end_1.y - vertical_offset_arrow_1;
//
//    fl_line(end_1.x, end_1.y, arrow_end_x_1, arrow_end_y_1);
//
//    double angleEY = asin(vertical_offset_line / line_length) * 180.0/PI;
//
//    // angle between arrowhead and Y axis
//    double angleAY = angleEY + ARROW_ANGLE;
//    double vertical_offset_arrow_2 = sin(180 - 90 - angleAY) * ARROW_LENGTH;
//    double horizontal_offset_arrow_2 = sin(angleAY) * ARROW_LENGTH;
//
//    double arrow_end_x_2 = end_1.x + horizontal_offset_arrow_2,
//        arrow_end_y_2 = end_1.y + vertical_offset_arrow_2;
//
//    fl_line(end_1.x, end_1.y, arrow_end_x_2, arrow_end_y_2);
//    fl_line(arrow_end_x_1, arrow_end_y_1, arrow_end_x_2, arrow_end_y_2);
//}

int main() {
    using namespace Graph_lib;

    Simple_window win(Point(200, 200), 800, 800, "Window");

    Arrow a(Point(100, 500), Point(500, 300));
    Arrow b(Point(500, 500), Point(200, 150));

    win.attach(a);
    win.attach(b);

    win.wait_for_button();

    return 0;
}

