#include "../std_lib_facilities.h"
#include <cmath>

class Rational {
    private:
        int num;
        int denom;

    public:
        Rational(int n, int d)
            : num(n), denom(d)
        {
            if (num == 0 || denom == 0) error("Zero values are prohibited.");
        }

        int get_num(){return num;}
        int get_denom(){return denom;}

        friend bool operator==(Rational& r1, Rational& r2) {
            return r1.get_num() == r2.get_num() && r1.get_denom() == r2.get_denom();
        }

        friend bool operator!=(Rational& r1, Rational& r2) {
            return !(r1 == r2);
        }
};

vector<int> factorize(int);

int find_lcd(int a, int b) {
    vector<int> f_a = factorize(a);
    vector<int> f_b = factorize(b);
    
    int lcd = 1;

    //sort factors before counting
    sort(f_a.begin(), f_a.end());
    sort(f_b.begin(), f_b.end());

    vector<vector<int> > runs_a;
    vector<vector<int> > runs_b;

    while (f_a.size()) {
        vector<int> run;
        int factor = f_a.back();
        f_a.pop_back();

        run.push_back(factor);

        while (f_a.back() == factor) {
            run.push_back(f_a.back());
            f_a.pop_back();
        }

        runs_a.push_back(run);
    }

    while (f_b.size()) {
        vector<int> run;
        int factor = f_b.back();
        f_b.pop_back();

        run.push_back(factor);

        while (f_b.back() == factor) {
            run.push_back(f_b.back());
            f_b.pop_back();
        }

        runs_b.push_back(run);
    }

    cout << runs_a[0][0] << " " << runs_b[0][0] << '\n';

    while (runs_a.size() && runs_b.size()) {
        vector<int> run = runs_a.back();
        runs_a.pop_back();

        for (int i=0; i<runs_b.size(); i++) {
            if (runs_b[i][0] == run[0]) {
                lcd *= run[0] * (runs_b[i].size() > run.size() ? runs_b.size() : run.size());
                runs_b.erase(runs_b.begin()+i);
                break;
            }
        }
    }

    if (runs_a.size() || runs_b.size()) {
        vector<vector<int> >& last_run = runs_a.size() > runs_b.size() ? runs_a : runs_b;

        for (int i=0; i<last_run.size(); i++) {
            lcd *= last_run[i].size() * last_run[i][0];
        }
    }

    return lcd;
}


/**
 * Finds prime numbers up to `max` number.
 */
vector<int> find_primes(int max) {
    vector<int> primes;
    bool prime = true;

    for (int i=1; i<=max; i++) {
        prime = true;

        for (int ii=2; ii<=i; ii++) {
            if (i%ii == 0 && i != ii) {
                prime = false;
                break;
            }
        }

        if (prime) primes.push_back(i);
    }

    return primes;
}


/**
 * Finds prime factors of a number `n`
 */
vector<int> factorize(int n) {
    vector<int> primes = find_primes(ceil(sqrt(n)));
    vector<int> factors;

    for (int p=0; p<primes.size(); p++) {
        if (primes[p] == 1) continue;
        if (n % primes[p] == 0 && n != 1) {
            factors.push_back(primes[p]);
            n = n/primes[p];
            p=-1;
        }
    }

    if (n > 1) factors.push_back(n);

    return factors;
}

int main() {
    /*vector<int> factors1 = factorize(12);
      vector<int> factors2 = factorize(10);

      cout << "Found for f1: " << factors1.size() << '\n';
      for (int i=0; i<factors1.size(); i++) {
      cout << factors1[i] << '\n';
      }

      cout << "Found for f2: " << factors2.size() << '\n';
      for (int i=0; i<factors2.size(); i++) {
      cout << factors2[i] << '\n';
      }*/

    cout << find_lcd(10, 12) << '\n';

    return 0;
}
