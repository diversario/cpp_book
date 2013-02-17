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
    string i_file = "input.txt";
    string o_file = "output.txt";
    char ch;

    ifstream ifs(i_file.c_str(), ios_base::binary);
    ofstream ofs(o_file.c_str(), ios_base::binary);
    
    char c;
    int length = 0;
    while(ifs.read(as_bytes(c), 1)) {
        length++;
    }

    ifs.clear();
    
    while(ifs.seekg(--length) && ifs.read(as_bytes(ch), sizeof(char))) {
        ofs.write(as_bytes(ch), sizeof(char));
    }

    keep_window_open();

    return 0;
}