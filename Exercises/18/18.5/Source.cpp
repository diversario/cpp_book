#include "../../../Includes/std_lib_facilities.h"

char* cat_dot(const char* s1, const char* s2, const char c) {
    int l1 = 0;
    int l2 = 0;

    while(*(s1+ l1++));
    while(*(s2+ l2++));

    char* cat = new char[l1+l2-1];

    cat[l1-1] = c;

    int i=0;

    while(i<l1-1) {
        cat[i] = s1[i];
        i++;
    }

    i=0;

    while(i<l2) {
        cat[i+l1] = s2[i];
        i++;
    }

    return cat;
}

int main(){
    char* s1 = "cat";
    char* s2 = "fish";

    char* c = cat_dot(s1, s2, ':');

    cout << c << endl;

    keep_window_open();
}