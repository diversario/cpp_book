#include "../std_lib_facilities.h"

struct Stats {
    double min;
    double max;
    double avg;
    double median;
};

Stats calculate_stats(vector<double>& v) {
    if (!v.size()) error("Empty vector.");

    Stats stats;
    stats.max = -INFINITY;
    stats.min = INFINITY;

    double sum = 0;
    vector<double> sorted;

    // get max, min values and sum
    for (int i=0; i<v.size(); i++) {
        if (stats.max < v[i]) stats.max = v[i];
        if (stats.min > v[i]) stats.min = v[i];
        sum += v[i];

        sorted.push_back(v[i]);
    }

    stats.avg = sum/v.size();

    sort(sorted.begin(), sorted.end());

    if (sorted.size()%2) stats.median = sorted[(sorted.size())/2];
    else stats.median = double(sorted[sorted.size()/2] + sorted[(sorted.size()/2)-1]) / 2;

    return stats;
}

int main(){
    vector<double> v;
    double n;

    cout << "Numbers:\n";

    while (cin >> n) {
        v.push_back(n);
    }

    cin.clear();

    Stats stats = calculate_stats(v);

    printf("Max: %f\n", stats.max);
    printf("Min: %f\n", stats.min);
    printf("Avg: %f\n", stats.avg);
    printf("Median: %f\n", stats.median);

    return 0;
}
