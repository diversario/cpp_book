class Patron {
public:
    Patron(string n, int c, double f)
    : name(n), lib_card(c), fees(f), in_debt(fees > 0) {}

    string get_name() const {return name;}
    int get_lib_card() const {return lib_card;}
    double get_fees() const {return fees;}
    bool if_owns() const {return in_debt;}

    void set_fee(double fee) {fees = fee; in_debt = fee > 0;}

    friend ostream& operator<<(ostream& os, Patron p) {
        os << p.name << ", " << p.lib_card << ", " << p.fees << ".\n";
        return os;
    }

private:
    string name;
    int lib_card;
    double fees;
    bool in_debt;
};
