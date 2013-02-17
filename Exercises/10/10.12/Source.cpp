#include "../../std_lib_facilities.h"

void find_word(string path, string word) {
    string input;
    int line = 0;

    ifstream ifs(path.c_str());

    if (!ifs) error("Could not open file.");
    
    while (true) {
        if (getline(ifs, input)) {
            line++;
            for (int i=0; i<input.size(); i++) {
                if (input[i] == word[0]) {
                    bool found = true;

                    for (int ii=1; ii<word.size(); ii++) {
                        if (input[i+ii] != word[ii]) {
                            found = false;
                            break;
                        }
                    }

                    if (found) cout << line << ": " << input << endl;
                }
            }
        } else {
            if (!ifs) break;
        }
    }
}

int main () {
    string path = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\10\\10.12\\words.txt";

    find_word(path, "poop");

    keep_window_open();

    return 0;
}