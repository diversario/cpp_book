#include "../../std_lib_facilities.h"


class Reading {
public:
    int hour;
    double temp;
    Reading(int h, double t): hour(h), temp(t) {}

    friend ostream& operator<<(ostream& os, Reading& r) {
        return os << r.hour << ' ' << r.temp << endl;
    }
};

int not_a_reading = -999;

class Day {
public:
    vector<double> hour;

    Day() : hour(24) {
        for (int i=0; i<hour.size(); i++) hour[i] = not_a_reading;
    }

    friend ostream& operator<<(ostream& os, Day& d) {
        for (int i=0; i<d.hour.size(); i++) {
            if (d.hour[i] != not_a_reading)
                os << " (" << i << ',' << d.hour[i] << ")";
        }

        return os;
    }
};

int not_a_month = -1;

class Month {
public:
    vector<Day> day;
    int month;

    Month()
        : month(not_a_month), day(32) {}

    friend ostream& operator<<(ostream& os, Month& m) {
        os << "{ month " << m.month << endl << '\t';

        for (int i=0; i<m.day.size(); i++) os << m.day[i];
        
        os << '}' << endl;
        return os;
    }
};


class Year {
public:
    int year;
    vector<Month> month;

    Year(int y): year(y) {}

    friend ostream& operator<<(ostream& os, Year& y) {
        os << "{ year " << y.year << endl;

        for (int i=0; i<y.month.size(); i++) os << y.month[i];

        os << "}" << endl;

        return os;
    }
};


int main () {
    vector<Reading> readings;
    vector<Month> months;
    Year year(2012);


    /**
     * Build readings
     */
    for (int i=0; i<32*25; i++) {
        int h = rand() % 24;
        double t = rand() % 100;

        Reading r(h, t);
        readings.push_back(r);
    }


    /**
     * Build months
     */
    for (int i=0; i<12; i++) {
        Month m;
        m.month = i;

        for (int ii=1; ii<32; ii++) {
            for (int hh=0; hh<24; hh++) {
                int index = (hh + ii) * (i+1);
                int h = readings[index].hour;
                m.day[ii].hour[h] = readings[index].temp;
            }
        }

        months.push_back(m);
    }

    for (int i=0; i<months.size(); i++) {
        year.month.push_back(months[i]);
    }

    cout << year;

    keep_window_open();

    return 0;
}