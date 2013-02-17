#include "../../../Includes/std_lib_facilities.h"

template<typename T> void print_vector(vector<T>& v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << endl;
    }
}

template<typename T> void f(vector<T>& v1, vector<T>& v2) {
    if (v1.size() != v2.size()) throw runtime_error(string("Vectors must be of equal size"));

    for (int i=0; i<v1.size(); i++) {
        v1[i] += v2[i];
    }
};

int main() {
    vector<int> v1;
    vector<int> v2;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    f(v1, v2);

    print_vector(v1);

    keep_window_open();
}