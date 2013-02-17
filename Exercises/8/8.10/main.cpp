#include "../std_lib_facilities.h"

double index(vector<double>& price, vector<double>& weight) {
    double index;

    for (int i=0; i<weight.size() && i<price.size(); i++) {
        index += weight[i]*price[i];
    }

    return index;
}

int main(){
    vector<double> weights;
    vector<double> prices;
    double weight;
    double price;

    cout << "Weights:\n";

    while (cin >> weight) {
        weights.push_back(weight);
    }

    cin.clear();
    cout << "Prices:\n";

    while (cin >> price) {
        prices.push_back(price);
    }

    if (prices.size() < weights.size()) error("Weights > Prices.");

    printf("Index: %f\n", index(prices, weights));

    return 0;
}
