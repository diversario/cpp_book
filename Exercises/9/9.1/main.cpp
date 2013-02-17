#include "../std_lib_facilities.h"

class Name_pairs {
private:
    vector<string> names;
    vector<double> ages;

public:
    void read_names();
    void read_ages();
    void sort();

    ostream& print(ostream&) const;
    int size() const;
    string get_name(int i) const;
    double get_age(int i) const;
};

int Name_pairs::size() const {
    return names.size();
}

string Name_pairs::get_name(int i) const {
    return i < names.size() ? names[i] : "";
}

double Name_pairs::get_age(int i) const {
    return i < ages.size() ? ages[i] : 0;
}

void Name_pairs::read_names() {
    string name;

    printf("Enter names:\n");

    cin.clear();

    while (cin >> name) {
        names.push_back(name);
    }

    cin.clear();
}

void Name_pairs::read_ages() {
    double age;

    cin.clear();

    for (int i = 0; i < names.size(); i++) {
        printf("Age of %s:\n", names[i].c_str());
        cin >> age;

        if (age >= 0) {
            ages.push_back(age);
        } else {
            error("Invalid age.");
        }
    }
}

ostream& Name_pairs::print(ostream& os) const {
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << ": " << ages[i] << '\n';
    }

    return os;
}

void Name_pairs::sort() {
    vector<string> names_copy = names;
    vector<double> ages_sorted(ages.size());

    ::sort(names.begin(), names.end());

    for (int i = 0; i < names.size(); i++) {
        for (int ii = 0; ii < names_copy.size(); ii++) {
            if (names_copy[ii] == names[i]) {
                ages_sorted[i] = ages[ii];
            }
        }
    }

    ages = ages_sorted;
}


ostream& operator<<(ostream& os, const Name_pairs& np) {
    return np.print(os);
}

bool operator==(const Name_pairs& np1, const Name_pairs& np2) {
    if (np1.size() != np2.size()) return false;

    for (int i=0; i < np1.size(); i++) {
        if (np1.get_name(i) != np2.get_name(i) || np1.get_age(i) != np2.get_age(i)) return false;
    }

    return true;
}

bool operator!=(const Name_pairs& np1, const Name_pairs& np2) {
    return !(np1 == np2);
}

int main() {
    Name_pairs names1;

    names1.read_names();
    names1.read_ages();

    cout << names1;

    Name_pairs names2;

    names2.read_names();
    names2.read_ages();

    cout << names2;

    cout << (names1 == names2);
    cout << (names1 != names2);

    return 0;
}
