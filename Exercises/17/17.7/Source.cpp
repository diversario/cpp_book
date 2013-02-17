#include "../../../Includes/std_lib_facilities.h"

int main () {
    char* c = new char[256];
    char ch;
    int i = 0;

    while(cin >> ch) {
        if (ch == '!') {
            c[i] = '\0';
            break;
        }
        c[i++] = ch;
    }

    cout << c;
    keep_window_open();
}