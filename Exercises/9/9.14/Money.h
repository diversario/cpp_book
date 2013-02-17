#include "../std_lib_facilities.h"

class Money {
private:
    long int amount;
    string currency;

public:
    Money(): amount(0), currency("USD") {};
    Money(string curr, double dollar_amount) {
        if (curr.size() != 3) throw runtime_error("Invalid currency code.");

        currency = curr;
        double cents = dollar_amount * 100;

        int integer_cents = int(cents);

        amount = (cents - integer_cents) >= 0.5 ? integer_cents + 1 : integer_cents;
    }


    long int get_amount() const {return amount;}
    string get_currency() const {return currency;}
    void set_amount(long int n) {amount = n;}
};