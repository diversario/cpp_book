#include "../../../Includes/std_lib_facilities.h"

int strcmp(const char* s1, const char* s2) {
    int offset = 0;

    while(*(s1+offset) && *(s2+offset)) {
        if (*(s1+offset) < *(s2+offset)) return -1;
        if (*(s1+offset) > *(s2+offset)) return 1;
        offset++;
    }

    if (!*(s1+offset) && !*(s2+offset)) return 0;
    if (!*(s1+offset)) return -1;
    if (!*(s2+offset)) return 1;

    throw runtime_error("Oops! Shouldn't've happened.");
}

int main() {
    char* s1 = "string2";
    char* s2 = "string2";

    int i = strcmp(s1, s2);

    cout << i;
    keep_window_open();
}