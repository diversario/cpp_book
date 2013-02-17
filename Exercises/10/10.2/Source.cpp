#include "../../std_lib_facilities.h"

int main () {
    string path = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\10\\10.2\\num.txt";

    int h;
    double t;
    char unit;

    ofstream ofs(path.c_str());
    if (!ofs) error("Could not open file for writing.");

    for (int i=0; i<50; i++) {
        h = rand() % 24;
        t = rand() % 100;
        unit = int(t)%2 == 0 ? 'c' : 'f';

        ofs << h << ' ' << unit << t << endl;
    }

    keep_window_open();

    return 0;
}