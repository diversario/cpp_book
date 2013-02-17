#include "../std_lib_facilities.h"
#include "Money.h"
#include "Exchange.h"

Exchange exchange;

ostream& operator<<(ostream& os, const Money& m) {
    cout << m.get_currency() << m.get_amount()/100.00 << '\n';
    return os;
}

Money operator+(const Money& m1, const Money& m2) {
    if (m1.get_currency() != "USD") runtime_error("First currency must be USD");

    double factor;

    try {
        factor = exchange.get_rate(m2.get_currency());
    } catch (runtime_error e) {
        throw runtime_error("No conversion rate found.");
    }

    Money m;
    m.set_amount(m1.get_amount() + m2.get_amount()*factor);

    return m;
}

Money operator-(const Money& m1, const Money& m2) {
    if (m1.get_currency() != m2.get_currency()) throw runtime_error("Currency mismatch.");

    Money m;
    m.set_amount(m1.get_amount() - m2.get_amount());

    return m;
}

Money operator/(const Money& m1, const double div) {
    Money m;

    double result = m1.get_amount() / div;
    int integer_result = int(result);

    m.set_amount((result - integer_result) >= 0.5 ? integer_result + 1 : integer_result);

    return m;
}

Money operator*(const Money& m1, const double div) {
    Money m;

    double result = m1.get_amount() * div;
    int integer_result = int(result);
    int rounded;

    if ((result - integer_result) >= 0.5) rounded = integer_result + 1;
    else rounded = integer_result;

    m.set_amount(rounded);

    return m;
}

int main() {
    exchange.set_rate("AUD", 0.5);
    exchange.set_rate("DKK", 1.5);

    Money m1("USD", 12.23);
    Money m2("USD", 1.14);
    Money m3("USD", 0.09);

    Money m4("AUD", 1.00);
    Money m5("UKP", 5.00);

    cout << "+ " << m1 + m2;
    cout << "- " << m1 - m2;
    cout << "/ " << m3 / 2.1;
    cout << "* " << m3 * 2;
    cout << "AUD + USD " << m1 + m4;
    cout << "UKP + USD " << m1 + m5;

    return 0;
}