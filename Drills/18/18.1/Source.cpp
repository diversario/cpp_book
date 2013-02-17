#include "../../../Includes/std_lib_facilities.h"

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(const int a[], int n) {
    int la[10];

    for (int i=0; i<10; i++) {
        la[i] = ga[i];
    }

    for (int i=0; i<10; i++) {
        cout << "la: " << la[i] << endl;
    }

    int* p = new int[n];

    for (int i=0; i<n; i++) {
        p[i] = a[i];
    }

    for (int i=0; i<n; i++) {
        cout << "p: " << p[i] << endl;
    }

    delete[] p;
}

int main(){
    int poop[10] = {10, 20, 40, 80, 160, 320, 640, 1280, 2560, 5120};

    f(ga, 10);
    f(poop, 10);

    keep_window_open();
}