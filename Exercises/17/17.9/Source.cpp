#include "../../../Includes/std_lib_facilities.h"

int main () {
    char* c1 = new char('a');
    char* c2 = new char('b');

    cout << (c1 < c2) << endl;

    keep_window_open();
}