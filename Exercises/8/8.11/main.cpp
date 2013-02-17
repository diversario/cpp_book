#include "../std_lib_facilities.h"

template<class A> A maxv(vector<A>& v) {
    if (!v.size()) error("Empty vector");

    A max = v[0];

    for (int i=1; i<v.size(); i++) {
        if (max < v[i]) {
            max = v[i];
        }
    }

    return max;
}

int main(){
    vector<double> v;
    double n;

    cout << "Numbers:\n";

    while (cin >> n) {
        v.push_back(n);
    }

    cin.clear();

    printf("Max: %f\n", maxv(v));

    vector<string> vs;
    string s;

    cout << "Strings:\n";

    while (cin >> s) {
        vs.push_back(s);
    }

    printf("Max: %s\n", maxv(vs).c_str());

    return 0;
}
