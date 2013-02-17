#include "../../std_lib_facilities.h"

struct Chars {
    string type;
    int count;
    Chars(string s, int i): type(s), count(i) {}
};

void add_char(vector<Chars>& chars, string type) {
    for (int i=0; i<chars.size(); i++) {
        if (chars[i].type == type) {
            chars[i].count++;
            return;
        }
    }

    Chars ch(type, 1);
    chars.push_back(ch);
}

vector<Chars> count_chars(ifstream& ifs) {
    char ch;
    vector<Chars> chars;

    while(ifs.get(ch)) {
        if(isspace(ch)) add_char(chars, string("whitespace"));
        if (isalpha(ch)) add_char(chars, string("alphabetical"));
        if (isdigit(ch)) add_char(chars, string("digit"));
        if (isxdigit(ch)) add_char(chars, string("hex digit"));
        if (isupper(ch)) add_char(chars, string("uppercase"));
        if (islower(ch)) add_char(chars, string("lowercase"));
        if (isalnum(ch)) add_char(chars, string("alphanumerical"));
        if (iscntrl(ch)) add_char(chars, string("control char"));
        if (ispunct(ch)) add_char(chars, string("punctuation"));
        if (isprint(ch)) add_char(chars, string("printable"));
        if (isgraph(ch)) add_char(chars, string("graphic"));
    }

    return chars;
}

int main() {
    string file = "input.txt";

    ifstream ifs(file.c_str());
    if (!ifs) error("Could not open file for reading.");

    vector<Chars> chars = count_chars(ifs);

    for (int i=0; i<chars.size(); i++) {
        cout << chars[i].type << ": " << chars[i].count << endl;
    }

    keep_window_open();

    return 0;
}