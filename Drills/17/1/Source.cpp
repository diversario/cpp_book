#include "../../../Includes/std_lib_facilities.h"

void print_array10(ostream& os, int* a) {
    int i = 0;
    while (i < 10)
        os << a[i++] << endl;

    i = a[i];
    if (i == 110) os << i << endl;
}

void print_array_n(ostream& os, int* a, int n) {
    int i = 0;
    while (i < n)
        os << a[i++] << endl;
}

void print_vector_n(ostream& os, vector<int> a) {
    int i = 0;
    while (i < a.size())
        os << a[i++] << endl;
}


int main () {
    int* ints10 = new int[10];

    for (int i=0; i<10; i++) {
        ints10[i] = i + 1;
    }

    print_array10(cout, ints10);
    delete[] ints10;

    /***************************/

    int* ints100 = new int[10];

    for (int i=0; i<10; i++) {
        ints100[i] = i + 100;
    }

    print_array10(cout, ints100);
    delete[] ints100;

    /***************************/

    int* ints111 = new int[11];

    for (int i=0; i<11; i++) {
        ints111[i] = i + 100;
    }

    print_array_n(cout, ints111, 11);
    delete[] ints111;

    /***************************/

    int* ints20 = new int[20];

    for (int i=0; i<20; i++) {
        ints20[i] = i + 100;
    }

    print_array_n(cout, ints20, 20);
    delete[] ints20;

    /***************************/

    vector<int> v_int_10(10);

    for (int i=0; i<10; i++) {
        v_int_10[i] = i + 100;
    }

    print_vector_n(cout, v_int_10);

    keep_window_open();
    return 0;
}