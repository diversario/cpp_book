#include "../../std_lib_facilities.h";

int main () {
    string input_path = "input.txt",
        output_path = "output.txt";

    ifstream ifs(input_path.c_str());
    ofstream ofs(output_path.c_str());
    ostringstream ostr;

    char s;

    while(ifs.get(s)) {
        if (isalpha(s)) s = tolower(s);
        ostr << s;
    }

    ofs << ostr.str();

    return 0;
}