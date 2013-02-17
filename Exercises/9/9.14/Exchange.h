#include "../std_lib_facilities.h"

class Exchange {
private:
    string base_currency;

    vector<string> currency;
    vector<double> factor;

public:
    Exchange(): base_currency("USD") {}
    double get_rate(string);
    void set_rate(string, double);
};

double Exchange::get_rate(string target_currency) {
    if (target_currency == base_currency) return 1.0;

    for (int i=0; i<currency.size(); i++) {
        if (currency[i] == target_currency) return factor[i];
    }

    throw runtime_error("Currency not found.");
}

void Exchange::set_rate(string new_currency, double new_factor) {
    if (new_factor <= 0) throw runtime_error("Factor cannot be less or equal to 0.");
    int index = -1;

    for (int i=0; i<currency.size(); i++) {
        if (currency[i] == new_currency) index = i;
    }

    if (index == -1) {
        currency.push_back(new_currency);
        factor.push_back(new_factor);
    } else {
        factor[index] = new_factor;
    }
}