#include <iostream>

class vector {
    int sz;
    double* elem;
public:
    vector(int n): sz(n) {
        elem = new double[n];
    }

    double* operator[](int n) {return &elem[n];}
};

int main() {
    vector v(10);
    //int x = v[2];

    *v[3] = 2;

    int i;
    std::cin >> i;
}