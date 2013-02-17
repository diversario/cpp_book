#include <iostream>

class Base {
public:
    Base(int ii): i(ii) {}
    ~Base() {
        std::cout << "Base is destroyed\n";
    }
private:
    int i;
};

class VirtualBase {
public:
    VirtualBase(int ii): i(ii) {}
    virtual ~VirtualBase() {
        std::cout << "VirtualBase is destroyed\n";
    }
private:
    int i;
};

class Derived : public Base {
public:
    Derived(int i) : Base(i) {}
    ~Derived() {
        std::cout << "Derived is destroyed\n";
    }
};

class VirtualDerived : public VirtualBase {
public:
    VirtualDerived(int i) : VirtualBase(i) {}
    ~VirtualDerived() {
        std::cout << "VirtualDerived is destroyed\n";
    }
};

void test() {
    Base B1(1);
    VirtualBase VB1(2);
    Derived D1(3);
    VirtualDerived VD1(4);
}

int main() {
    test();

    int i;
    std::cin >> i;
}