#include "../std_lib_facilities.h"

class Point {
private:
    int x;
    int y;

public:
    Point(void){};
    Point(int xx, int yy): x(xx), y(yy) {};

    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }

    friend ostream& operator<<(ostream& os, Point& p) {
        os << '(' << p.x << ',' << p.y << ')' << endl;
        return os;
    }

    friend bool operator==(Point& p1, Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }

    friend bool operator!=(Point& p1, Point& p2) {
        return !(p1 == p2);
    }
};

