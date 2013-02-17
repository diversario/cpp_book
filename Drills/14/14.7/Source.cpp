#include "../../../std_lib_facilities.h"

class B2 {
public:
    virtual void pvf() const {
        cout << "B1!\n";
    };
};


class D21 : public B2 {
public:
    string m;

    D21(string ss): m(ss) {}

    void pvf() const {
        printf("D21::pvf - %s\n", m.c_str());
    }
};

class D22 : public B2 {
public:
    int m;

    D22(int ii): m(ii) {}

    void pvf() const {
        printf("D22::pvf - %d\n", m);
    }

};

void f(const B2& b) {
    b.pvf();
}

int main () {
    D21 d21("string");
    D22 d22(69);

    f(d21);
    f(d22);

    keep_window_open();

    return 0;
}