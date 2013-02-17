#include "../../../Includes/std_lib_facilities.h"

template<class T> struct S {
    S(): val(T()) {}
    S(T tt): val(tt) {}

    const T& get() const;
    T& get();
    
    S& operator=(const T&);

private:
    T val;
};

template<class T> const T& S<T>::get() const {return val;}
template<class T> T& S<T>::get() {return val;}
template<class T> S<T>& S<T>::operator=(const T& v) {val = v; return *this;}

template<class T> void read_val(T& v) {
    cout << "Enter value:" << endl
         << ">> " << endl;
    cin >> v;
}

int main(int argc, const char* argv[]){
    S<int> si;
    S<char> sc;
    S<double> sd;
    S<string> ss;

    read_val(si.get());
    read_val(sc.get());
    read_val(sd.get());
    read_val(ss.get());

    vector<int> vi;
    vi.push_back(7);

    S<vector<int>> sv(vi);

    cout << si.get() << endl
         << sc.get() << endl
         << sd.get() << endl
         << ss.get()  << endl
         << sv.get()[0] << endl
    ;

    keep_window_open();

    return 0;
}