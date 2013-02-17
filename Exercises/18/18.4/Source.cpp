#include "../../../Includes/std_lib_facilities.h"

char* cat_dot(const string& s1, const string& s2) {
    char* cat = new char[s1.size() + 1 + s2.size() + 1]; // dot and '\0'

    for (int i=0; i<s1.size(); i++) cat[i] = s1[i];

    cat[s1.size()] = '.';

    for (int i=0; i<s2.size(); i++) {
        cat[s1.size()+i + 1] = s2[i];
    }

    cat[s1.size()+s2.size()+1] = '\0';

    return cat;
}

int main() {
    string s1("cat");
    string s2("poop");

    char* c = cat_dot(s1, s2);

    cout << c << endl;

    keep_window_open();
}