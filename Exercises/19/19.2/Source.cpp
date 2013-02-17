#include "../../../Includes/std_lib_facilities.h"
    
template<typename T, typename U> double f(vector<T>& vt, vector<U>& vu) {
    int length = (vt.size() > vu.size()) ? vu.size() : vt.size();
    double sum = 0;
    
    for (int i=0; i<length; i++) {
        sum += vt[i] * vu[i];
    }

    return sum;
}

int main() {
    vector<int> v1;
    vector<double> v2;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(99);

    v2.push_back(1.1);
    v2.push_back(2.2);
    v2.push_back(3.3);

    cout << f(v1, v2) << endl;

    keep_window_open();
}