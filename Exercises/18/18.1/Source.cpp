#include "../../../Includes/std_lib_facilities.h"

char* strdup(const char* s) {
    int length=0;
    char* p = const_cast<char*>(s);

    while(*p) {
        length++;
        p++;
    }

    p -= length;

    char* copy = new char[length+1];

    while(*p) {
        *copy = *p;
        copy++; p++;
    }

    *copy = '\0';
    copy -= length;

    return copy;
}

int main() {
    char* ch = "some string";
    char* copy = strdup(ch);

    cout << copy << endl;

    keep_window_open();
}