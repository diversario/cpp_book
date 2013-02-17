#include "../../std_lib_facilities.h"

double sum_file(string path) {
    int total = 0
        , n;

    ifstream ifs(path.c_str());

    if (!ifs) error("Could not open file.");

    while (true) {
        if (ifs >> n) total += n;
        else {
            if (ifs.fail()) {
                ifs.clear();
                char c;
                while (ifs >> c && !isdigit(c));
                if (!ifs) break;
                ifs.unget();
            }

            if (ifs.eof()) break;
        }
    }

    return total;
}

int main () {
    string path = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\10\\10.11\\num.txt";

    double sum = sum_file(path);

    cout << sum << endl;

    keep_window_open();

    return 0;
}