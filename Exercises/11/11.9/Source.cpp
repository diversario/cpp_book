#include "../../std_lib_facilities.h"

vector<string> split(const string& s) {
    istringstream istr(s);
    vector<string> strings;
    string ss;

    while(istr >> ss) {
        strings.push_back(ss);
    }

    return strings;
}

int main() {
    string file = "input.txt";
    string s;

    ifstream ifs(file.c_str());

    while(getline(ifs, s)) {
        vector<string> v = split(s);

        for (int i=0; i<v.size(); i++) {
            cout << v[i] << endl;
        }
    }

    keep_window_open();

    return 0;
}