#include "../../std_lib_facilities.h"

int main() {
    string s;

    while(getline(cin, s) && s.size() > 0) {
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            cout << c << ": ";
            if (isspace(c)) cout << "whitespace ";
            if (isalpha(c)) cout << "letter ";
            if (isdigit(c)) cout << "decimal ";
            if (isxdigit(c)) cout << "hexadecimal ";
            if (isupper(c)) cout << "uppercased ";
            if (islower(c)) cout << "lowercased ";
            if (iscntrl(c)) cout << "control-char ";
            if (ispunct(c)) cout << "punctuation ";
            if (isprint(c)) cout << "printable ";
            if (isgraph(c)) cout << "graphic ";
            cout << endl;
        }
    }

    keep_window_open();

    return 0;
}