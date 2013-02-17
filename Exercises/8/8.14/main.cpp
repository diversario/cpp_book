#include "../std_lib_facilities.h"

struct Extremes {
    string shortest;
    string longest;
    string lex_first;
    string lex_last;
};

vector<int> get_lengths(vector<string>& v) {
    if (!v.size()) error("Empty vector.");

    vector<int> lengths;

    // get max, min values and sum
    for (int i=0; i<v.size(); i++) {
        lengths.push_back(v[i].size());
    }

    return lengths;
}

Extremes find_extremes(vector<string>& v) {
    if (!v.size()) error("Empty vector.");

    Extremes minmax;
    minmax.shortest = v[0];
    minmax.lex_first = v[0];
    minmax.lex_last = v[0];

    for (int i=0; i<v.size(); i++) {
        if (v[i].size() < minmax.shortest.size()) minmax.shortest = v[i];
        if (v[i].size() > minmax.longest.size()) minmax.longest = v[i];

        if (v[i] < minmax.lex_first) minmax.lex_first = v[i];
        if (v[i] > minmax.lex_last) minmax.lex_last = v[i];
    }

    return minmax;
}

int main(){
    vector<string> vs;
    string s;

    cout << "Strings:\n";

    while (getline(cin, s)) {
        vs.push_back(s);
    }

    vector<int> string_lengths = get_lengths(vs);

    for (int i=0; i<string_lengths.size(); i++) {
        printf("%s: %d\n", vs[i].c_str(), string_lengths[i]);
    }

    Extremes minmax = find_extremes(vs);
    printf("Shortest: %s\n", minmax.shortest.c_str());
    printf("Longest: %s\n", minmax.longest.c_str());

    printf("Lexicographically first: %s\n", minmax.lex_first.c_str());
    printf("Lexicographically last: %s\n", minmax.lex_last.c_str());

    return 0;
}
