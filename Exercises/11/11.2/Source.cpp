#include "../../std_lib_facilities.h"

ostringstream remove_chars(ifstream& source) {
    ostringstream ostr;
    string remove = "qeuioa";
    char ch;

    while(source.get(ch)) {
        bool skip = false;

        if (isalpha(ch)) {
            for (int i=0; i<remove.size(); i++) {
                if (tolower(ch) == remove[i]) {
                    skip = true;
                    break;
                }
            }
        }

        if (!skip) ostr << ch;
    }

    return ostr;
}

int main () {
    string input_path = "input.txt",
        output_path = "output.txt";

    ifstream ifs(input_path.c_str());
    ofstream ofs(output_path.c_str());
    
    ostringstream ostr = remove_chars(ifs);

    ofs << ostr.str();

    return 0;
}