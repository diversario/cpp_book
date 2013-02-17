#include "../../../std_lib_facilities.h"

class B1 {
public:
    virtual void vf() const {
        printf("B1::vf\n");
    }

    void f() const {
        printf("B1::f\n");
    }

    virtual void pvf() const =0;
};

class D1 : public B1 {
public:
    void vf() const {
        printf("D1::vf\n");
    }

    void f() const {
        printf("D1::f\n");
    }

    void pvf() const {
        printf("D1::pvf\n");
    }
};

class D2 : public D1 {
public:
    void pvf() const {
        printf("D2::pvf\n");
    }
};

int main () {
    //B1 b;

    //b.vf();
    //b.f();

    D1 d;

    d.vf();
    d.f();
    d.pvf();
    
    cout << endl;
    
    B1 &br = d;

    br.vf();
    br.f();
    br.pvf();

    cout << endl;

    D2 d2;

    d2.vf();
    d2.f();
    d2.pvf();

    keep_window_open();

    return 0;
}