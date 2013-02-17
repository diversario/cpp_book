#include "../../../Includes/std_lib_facilities.h"

void print_array_n(ostream& os, int* a, int n) {
    int i = 0;
    while (i < n)
        os << a[i++] << endl;
}

int main () {
    /*
    int* i1 = new int(7);
    int* p1 = i1;

    cout << p1 << endl;
    cout << *p1 << endl;

    /*****************************

    int* ia = new int[7];

    for (int i=0; i<7; i++) {
        ia[i] = pow(2, i);
    }

    int* p2 = ia;

    cout << p2 << endl;
    print_array_n(cout, ia, 7);

    /*****************************

    int* p3(p2);

    p2 = p1;
    p2 = p3;

    cout << "------------" << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    cout << *p1 << endl;
    print_array_n(cout, p2, 7);

    /*****************************

    delete p1;
    delete[] p2;
    //delete[] p3; // already deleted
    */
    /****************************/
    int* array1 = new int[10];

    for (int i=0; i<10; i++) {
        array1[i] = pow(2, i);
    }

    int* p1 = array1;
    
    int* array2 = new int[10];
    int* p2 = array2;
    
    for (int i=0; i<10; i++) {
        p2[i] = p1[i];
    }
    
    print_array_n(cout, p2, 10);
    keep_window_open();
    return 0;
}