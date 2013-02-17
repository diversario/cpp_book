#include "../../../Includes/std_lib_facilities.h"

int global1 = 5;
int global2 = 10;

int* f(int a) {
    return &a;
}

int main() {
    int* allocated1 = new int(2);
    int* allocated2 = new int(6);

    int* stack1 = f(3);
    int* stack2 = f(7);

    int* arr = new int[2];
    arr[0] = 9;
    arr[1] = 11;

    cout << "global1: " << &global1 << endl
         << "global2: " << &global2 << endl
         << "allocated1: " << &allocated1 << endl
         << "allocated2: " << &allocated2 << endl
         << "array1: " << &allocated1 << endl
         << "array2: " << &allocated2 << endl
         << "stack1: " << &stack1 << endl
         << "stack2: " << &stack2 << endl
         ;

    keep_window_open();
}