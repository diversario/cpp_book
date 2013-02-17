#include "../../std_lib_facilities.h"

int main() {
    string file1 = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\10\\10.8\\file1.txt",
        file2 = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\10\\10.8\\file2.txt",
        output = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\10\\10.8\\file1+2.txt";

    ifstream ifs1(file1.c_str()),
        ifs2(file2.c_str());

    if (!ifs1 || !ifs2) error("Could not open files for reading.");

    ofstream ofs(output.c_str());
    if (!ofs) error("Could not open files for writing.");

    char c;

    while(ifs1 >> c) ofs << c;
    while(ifs2 >> c) ofs << c;

    return 0;
}