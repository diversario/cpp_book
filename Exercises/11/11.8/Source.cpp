#include "../../std_lib_facilities.h"

void txt_to_bin(string path, string output_file_path) {
    ifstream ifs(path.c_str());

    if (!ifs) error("Can't open file for reading:", path);

    ofstream ofs(output_file_path.c_str(), ios_base::binary);

    vector<char> data;

    char ch;
    while(ifs >> ch) {
        data.push_back(ch);
    }

    for (int i=0; i<data.size(); i++) {
        ofs.write(as_bytes(data[i]), sizeof(char));
    }
}

void bin_to_txt(string path, string output_file_path) {
    ifstream ifs(path.c_str(), ios_base::binary);

    if (!ifs) error("Can't open file for reading:", path);

    ofstream ofs(output_file_path.c_str());

    vector<char> data;

    char ch;
    while(ifs.read(as_bytes(ch), sizeof(ch))) {
        data.push_back(ch);
    }

    for (int i=0; i<data.size(); i++) {
        ofs << data[i];
    }
}

int main() {
    string in1 = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\11\\11.8\\input.txt";
    string out1 = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\11\\11.8\\output.bin";

    string in2 = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\11\\11.8\\input.bin";
    string out2 = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\11\\11.8\\output.txt";

    txt_to_bin(in1, out1);
    bin_to_txt(in2, out2);

    return 0;
}