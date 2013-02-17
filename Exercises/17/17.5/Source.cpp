#include "../../../Includes/std_lib_facilities.h"

char* findx(const char* x, const char* s) {
    int i=0;

    if (!x[0] || !s[0]) return 0;

    while(s[i]) {
        int ii = 0;

        while(s[i] && x[ii] && (s[i+ii] == x[ii])) ii++;

        if (!x[ii]) {
            char* r = new char[ii+1];

            for (int c=0; c < ii; c++) {
                r[c] = s[i+c];
            }

            r[ii] = '\0';

            return const_cast<char*>(r); 
        }

        i++;
    }
}

int main() {
    string s = "shitfuck";
    string x = "itfu";

    char* found = findx(x.c_str(), s.c_str());

    cout << found;    

    keep_window_open();
}