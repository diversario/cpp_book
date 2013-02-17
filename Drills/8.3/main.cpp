#include <iostream>

namespace X {
    int var;

    void print() {
        std::cout << "X::var: " << var << std::endl;
    }
}


namespace Y {
    int var;

    void print() {
        std::cout << "Y::var: " << var << std::endl;
    }
}

namespace Z {
    int var;

    void print() {
        std::cout << "Z::var: " << var << std::endl;
    }
}

int main() {
    X::var = 7;
    X::print();

    using namespace Y;

    var = 9;
    print();

    {
        using Z::var;
        using Z::print;

        var = 11;
        print();
    }

    print();
    X::print();

    return 0;
}
