#include "../../std_lib_facilities.h"

int main () {
    vector<int> numbers;
    vector<string> bases;

    cout << "Enter some numbers:\n";

    string s;

    while (cin >> s) {
        istringstream ist;
        ist.unsetf(ios::dec);
        ist.unsetf(ios::hex);
        ist.unsetf(ios::oct);
        int n;

        ist.str(s);

        ist >> n;
        numbers.push_back(n);

        if (s.size() >= 2 && s[1] == 'x') {
            bases.push_back("hex");
        } else if (s[0] == '0') {
            bases.push_back("oct");
        } else bases.push_back("dec");
    }

    for (int i=0; i<numbers.size(); i++) {
        cout << showbase << (bases[i] == "dec" ? dec : (bases[i] == "oct" ? oct : hex)) << numbers[i]
             << '\t' << bases[i] << "\tconverts to" << "\t"
             << dec << numbers[i] << "\tdecimal" << endl;
    }
    
    keep_window_open();

    return 0;
}