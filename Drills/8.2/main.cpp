#include <iostream>

using namespace std;

void swap_v(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//void swap_cr(const int& a, const int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}

int main() {
    int x = 7;
    int y = 9;

    swap_r(x, y);
    cout << x << ", " << y << '\n';

    const int cx = 7;
    const int cy = 9;

    swap_v(cx, cy);
    cout << cx << ", " << cy << '\n';

//    swap_cr(7.7, 9.9);
//    cout << cx << ", " << cy << '\n';

    double dx = 7.7;
    double dy = 9.9;

    swap_r(dx, dy);
    cout << cx << ", " << cy << '\n';
}
