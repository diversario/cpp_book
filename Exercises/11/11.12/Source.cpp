#include "../../std_lib_facilities.h"

string reverse(const string& s) {
    istringstream istr(s);

    vector<string> strings;
    string ss;

    while(istr >> ss) {
        strings.push_back(ss);
    }

    string reversed;

    for (int i=strings.size()-1; i>=0; i--) {
        if (i!=strings.size()-1) reversed += ' ';
        reversed = string(reversed) + strings[i];
    }

    return reversed;
}

int main() {
    string i_file = "input.txt";
    string o_file = "output.txt";

    ifstream ifs(i_file.c_str(), ios_base::binary);
    if (!ifs) error("Could not open file for reading.");

    ofstream ofs(o_file.c_str(), ios_base::binary);

    char ch;
    string s;

    while(ifs.read(as_bytes(ch), sizeof(char))) {
        s += ch;
    }

    cout << reverse(s);

    keep_window_open();

    return 0;
}