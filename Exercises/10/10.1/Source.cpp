#include "../../std_lib_facilities.h"


double sum_file(string path) {
    int total = 0
      , n;

    ifstream ifs(path.c_str());
    
    if (!ifs) error("Could not open file.");

    while(ifs >> n) {
        total += n;
    }

    if (!cin.eof()) {
        cout << "Read interrupted." << endl;
    }

    return total;
}

int main () {
    string path = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\10\\10.1\\num.txt";

    double sum = sum_file(path);

    cout << sum << endl;

    keep_window_open();

    return 0;
}