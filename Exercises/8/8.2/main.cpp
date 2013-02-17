#include "std_lib_facilities.h"

void print(string label, const vector<int>& v) {
    for (int i=0; i<v.size(); i++) {
        cout << label << ": " << v[i];
    }
}

int main() {
    vector<int> v(3);

    v[0]=5;
    v[1]=7;
    v[2]=9;

    print("int", v);
}
