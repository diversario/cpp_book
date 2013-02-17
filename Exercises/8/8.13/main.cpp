#include "../std_lib_facilities.h"

void print_until_s(vector<string> s, string stop) {
    for (int i=0; i<s.size(); i++) {
        if (s[i] != stop) printf("%s\n", s[i].c_str());
        else {
            printf("Done!\n");
            break;
        }
    }
}

void print_until_ss(vector<string> s, string stop, int reps) {
    int occurences = 0;

    for (int i=0; i<s.size(); i++) {
        if (s[i] == stop) {
            if (++occurences >= reps) {
                printf("Done!\n");
                break;
            }
        }

        printf("%s\n", s[i].c_str());
    }
}

int main() {
    vector<string> vs;
    string s;

    cout << "Strings:\n";

    while (getline(cin, s)) {
        vs.push_back(s);
    }

    print_until_s(vs, "");
    print_until_ss(vs, "halt", 2);

    return 0;
}
