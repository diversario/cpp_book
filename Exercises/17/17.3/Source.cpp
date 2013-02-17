#include "../../../Includes/std_lib_facilities.h"

void to_lower(char* s) {
    while (*s) {
        if (*s >= 65 && *s <= 90) *s += 32;
        s++;
    }
}

int main() {
    string s = "ShIt!"; 
    char* c = const_cast<char*>(s.c_str());

    to_lower(c);

    for (int i=0; i<4; i++) {
        cout << c[i];
    }

    keep_window_open();
}