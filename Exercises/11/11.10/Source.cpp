#include "../../std_lib_facilities.h"

bool contains(const char& s, const string& w) {
    for (int i=0; i<w.size(); i++) {
        if (s == w[i]) return true;
    }

    return false;
}

vector<string> split(const string& s, const string& w) {
    string new_s = s;

    for (int i=0; i<new_s.size(); i++) {
        if(contains(new_s[i], w)) new_s[i] = ' ';
    }

    istringstream istr(new_s);
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
        vector<string> v = split(s, ",!'-");

        for (int i=0; i<v.size(); i++) {
            cout << v[i] << endl;
        }
    }

    keep_window_open();

    return 0;
}