#include "../../../Includes/std_lib_facilities.h"

class Iterator {
public:
    virtual double* next() =0;

protected:
    int pointer;
};

class Vector_iterator : public Iterator {
public:
    Vector_iterator(const vector<double>& vv): v(vv) {
        pointer = 0;
    }

    double* next();
private:
    vector<double> v;
};


double* Vector_iterator::next() {
    if (v.size() && v.size() > pointer) return &v[pointer++];
    else return 0;
}

class List_iterator : public Iterator {
public:
    List_iterator(const list<double>& vv): v(vv) {
        pointer = v.begin();
    }

    double* next();
private:
    list<double> v;
    list<double>::iterator pointer;
};

double* List_iterator::next() {
    double* p;

    if (v.size() && v.size() > std::distance(v.begin(), pointer)) {
        p = &*pointer;
        pointer++;
        return p;
    } else return 0;
}


void test(Iterator& it) {
    double* p;

    while ((p = it.next()) && *p != 0) {
        cout << *p << endl;
    }
}

int main() {
    vector<double> v;

    v.push_back(1.5);
    v.push_back(2.5);
    v.push_back(3.5);

    list<double> l;
    l.push_back(1.9);
    l.push_back(2.9);
    l.push_back(3.9);

    Vector_iterator vi(v);
    List_iterator li(l);

    test(li);
    test(vi);

    keep_window_open();

    return 0;
}