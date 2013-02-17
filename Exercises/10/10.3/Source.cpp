#include "../../std_lib_facilities.h"

class Reading {
private:
    int hour;
    double temp;

public:
    Reading(int h, double t): hour(h), temp(t) {
        if (hour < 0 || hour > 23) error("Hour is out of range.");
    }

    int get_hour() const {return hour;}
    double get_temp() const {return temp;}

    friend ostream& operator<<(ostream& os, Reading& r) {
        return os << r.hour << ' ' << r.temp << endl;
    }
};

struct Hourly_Average {
    int hour;
    void add_reading(double temp) {total += temp; divisor++;};
    double average() const {return divisor > 0 ? total/divisor : -300; }
    Hourly_Average(int h): hour(h), divisor(0), total(0) {}
    Hourly_Average(): hour(-1), divisor(0), total(0) {}

    friend ostream& operator<<(ostream& os, Hourly_Average& h) {
        return os << h.hour << ' ' << h.average() << endl;
    }
private:
    int divisor;
    double total;
};

double c_to_f(string c_raw) {
    double c = atof(c_raw.c_str());
    return 9*c/5 + 32;
}

/**
 * Populate Readings vector
 */
void populate_vector(vector<Reading>& r, const string& path) {
    ifstream ifs(path.c_str());
    if (!ifs) error("Could not open file for reading.");

    int hour;
    string temp_raw;
    double temp;

    while (ifs >> hour >> temp_raw) {
        if (temp_raw[0] == 'c') temp = c_to_f(temp_raw.substr(1, temp_raw.size()));
        else if (temp_raw[0] == 'f') temp = atof(temp_raw.substr(1, temp_raw.size()).c_str());
        r.push_back(Reading(hour, temp));
    }
}

void mean_temp_per_hour(vector<Hourly_Average>& averages, vector<Reading>& readings) {
    for (int i=0; i<readings.size(); i++) {
        bool found = false;

        for (int ii=0; ii<averages.size(); ii++) {
            if (averages[ii].hour == readings[i].get_hour()) {
                averages[ii].add_reading(readings[i].get_temp());
                found = true;
                break;
            }
        }

        if (!found) {
            Hourly_Average avg(readings[i].get_hour());
            avg.add_reading(readings[i].get_temp());
            averages[readings[i].get_hour()] = avg;
        }
    }
}

int main () {
    string path = "f:\\Documents\\Dropbox\\Documents\\Projects\\C++\\Exercises\\10\\10.2\\num.txt";
    vector<Reading> readings;
    vector<Hourly_Average> averages(24);

    populate_vector(readings, path);
    mean_temp_per_hour(averages, readings);

    for (int i=0; i<averages.size(); i++) {
        cout << averages[i];
    }

    keep_window_open();

    return 0;
}