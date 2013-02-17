#include "../../std_lib_facilities.h"

struct Chars {
    int num;
    int count;
    Chars(int n, int i): num(n), count(i) {}
};

void add_char(vector<Chars>& chars, int num) {
    for (int i=0; i<chars.size(); i++) {
        if (chars[i].num == num) {
            chars[i].count++;
            return;
        }
    }

    Chars ch(num, 1);
    chars.push_back(ch);
}

vector<Chars> count_chars(ifstream& ifs) {
    int num;
    vector<Chars> chars;

    while(ifs >> num) {
        add_char(chars, num);
    }

    return chars;
}

int main() {
    string file = "input.txt";

    ifstream ifs(file.c_str());
    if (!ifs) error("Could not open file for reading.");

    vector<Chars> chars = count_chars(ifs);

    for (int i=0; i<chars.size(); i++) {
        cout << setw(8) << chars[i].num;
        if (chars[i].count > 1) cout << setw(8) << chars[i].count;
        cout << endl;
    }

    keep_window_open();

    return 0;
}