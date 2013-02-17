class AbstractConstructor {
public:
    int i;
protected:
    AbstractConstructor(int ii) : i(ii) {}
};

class AbstractPureVirtual {
public:
    AbstractPureVirtual(int ii) : i(ii) {}
    int i;

    virtual int pv() const =0;
};

int main() {
    //AbstractPureVirtual ac(1);

    return 0;
}