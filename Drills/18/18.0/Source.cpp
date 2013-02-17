#include "../../../Includes/std_lib_facilities.h"

using namespace std;

struct X {
    int val;

    void out(const string& s, int nv) {
        cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
    }

    X(){out("X()", 0); val = 0;}
    X(int v) { out("X(int v) ", v); val = v;}
    X(const X& x) {out("X(X&) ", x.val); val = x.val;}
    X& operator=(const X& a) {
        out("X operator=()", a.val); val = a.val; return *this;
    }
    ~X() {out("~X() ", 0);}
};

X glob(2);
X copy(X a) {return a;}
X copy2(X a) {X aa = a; return aa;}
X& ref_to(X& a) {return a;}
X* make(int i) {X a(i); return new X(a);}

struct XX {X a; X b;};

void print_line(const char* s) {
    cout << endl << endl << s << endl;
}

int main(){
    print_line("loc 4");
    X loc(4); print_line("loc2 = loc");
    X loc2 = loc; print_line("loc = X 5"); 

    loc = X(5); print_line("loc2 = copy loc");
    loc2 = copy(loc); print_line("loc2 = copy2 loc");
    loc2 = copy2(loc); print_line("loc3 6");

    X loc3(6); print_line("&r = ref_to loc");

    X& r = ref_to(loc); print_line("delete make 7");

    delete make(7); print_line("delete make 8");
    delete make(8); print_line("vector X v 4");

    vector<X> v(4); print_line("XX loc4");

    XX loc4; print_line("X* p = new X 9");
    X* p = new X(9); print_line("delete p");
    delete p; print_line("X* pp = new X 5");
    X* pp = new X[5]; print_line("delete[] pp");
    delete[] pp; 

    keep_window_open();
}