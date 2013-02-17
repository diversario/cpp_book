#include "../../../Includes/std_lib_facilities.h"

int main () {
    ostringstream os;
    char ch;
    int i = 0;

    while(cin >> ch) {
        if (ch == '!') {
            break;
        }
        os << ch;
    }

    string s(os.str());

    cout << s;
    keep_window_open();
}