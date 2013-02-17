#include "../../../Includes/std_lib_facilities.h"

char* findx(const char* s, const char* x) {
    const char* source = s;
    const char* find = x;

    while (*source) {
        if (*source != *find) {
            source++;
            continue;
        }

        int offset = 1;

        while (*(source+offset) && *(find+offset) && *(source+offset) == *(find+offset)) {
            offset++;
        }

        if (!*(find+offset)) {
            char* found = new char[offset];
            found[offset] = '\0';

            for (int i=offset-1; i>=0; i--) found[i] = *(source+i);
            
            return found;
        }

        source++;
    }

    return 0;
}

int main() {
    char* s = "fuck pointers";
    char* x = "point";

    char* found = findx(s, x);

    cout << found;

    keep_window_open();
}