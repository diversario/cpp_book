#include "../../../Includes/std_lib_facilities.h"

char* strdup(const char* s) {
    int length = 0;

    while (s[length]) length++;

    char* copy = new char[length+1];

    int i = 0;
    while (i <= length) {
        copy[i] = s[i];
        i++;
    }

    copy[length] = '\0';
    return copy;
}

int main() {
    string s = "Sh0It!"; 
    const char* c = s.c_str();

    char* cp = strdup(c);

    for (int i=0; i<4; i++) {
        cout << cp[i];
    }

    keep_window_open();
}