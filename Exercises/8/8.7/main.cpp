//#include <iostream>
//#include <vector>
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;

#include "stdlib.h"

int main() {
    vector<string> names;
    vector<double> ages;

    string name;
    double age;

    cout << "Name?\n";

    while (cin >> name) {
        names.push_back(name);
    }

    for (int i=0; i<names.size(); i++) {
        cout << "Age of " << names[i] << " ?\n";
        cin.clear();
        cin >> age;
        ages.push_back(age);
    }

//    for (int i=0; i<names.size(); i++) {
//        printf("%s: %f\n", names[i].c_str(), ages[i]);
//    }

    vector<string> names_copy;

    for (int i=0; i<names.size(); i++) {
        names_copy.push_back(names[i]);
    }

    sort(names.begin(), names.end());

    for (int i=0; i<names.size(); i++) {
        string name = names[i];

        for (int ii=0; ii<names_copy.size(); ii++) {
            if (names_copy[ii] == name) {
                printf("%s: %f\n", name.c_str(), ages[ii]);
                break;
            }
        }
    }

    return 0;
}
