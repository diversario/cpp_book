#include "../../../Includes/std_lib_facilities.h"

template<class T> class Pair {
public:
    Pair(T nn, T vv): n(nn), v(vv) {}

    const T& name() const {return n;}
    T& name() {return n;}

    const T& value() const {return v;}
    T& value() {return v;}
private:
    T n;
    T v;
};

int main () {
    string n = "key";
    string v = "value";

    Pair p(n, v);
}