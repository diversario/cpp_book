#include "stdlib.h"

void print(string label, const vector<int>& v) {
    for (int i=0; i<v.size(); i++) {
        cout << label << ": " << v[i] << '\n';
    }
}

void print_s(string label, const vector<string>& v) {
    for (int i=0; i<v.size(); i++) {
        cout << label << ": " << v[i] << '\n';
    }
}

void fib(int x, int y, vector<int>& v, int n) {
    v.push_back(y);
    v.push_back(x);

    for (int i=1; i<n; i++) {
        int next = v[i] + v[i-1];
        v.push_back(next);
    }
}

void string_gen(vector<string>& v, int n) {
    v.push_back("stringA");

    for (int i=1; i<n; i++) {
        string next = v[v.size()-1];
        next[next.size()-1] = char(i+98);
        v.push_back(next);
    }
}

vector<int> swap_return(const vector<int> v) {
    vector<int> new_v;

    for (int i=v.size()-1; i>=0; i--) {
        new_v.push_back(v[i]);
    }

    return new_v;
}

void swap_in_place(vector<int>& v) {
    int temp;

    for (int i=0; i<v.size()/2; i++) {
        temp = v[i];
        v[i] = v[v.size()-1-i];
        v[v.size()-1-i] = temp;
    }
}

void swap_in_place(vector<string>& v) {
    string temp;

    for (int i=0; i<v.size()/2; i++) {
        temp = v[i];
        v[i] = v[v.size()-1-i];
        v[v.size()-1-i] = temp;
    }
}

int main() {
    vector<string> v;

    string_gen(v, 10);

    swap_in_place(v);
    print_s("FF", v);

    return 0;
}
