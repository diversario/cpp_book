#include "../std_lib_facilities.h"
#include <cmath>

int find_lcd(int, int);

class Rational {
    private:
        int num;
        int denom;

    public:
        Rational(int n=0, int d=1)
            : num(n), denom(d)
        {
            if (denom == 0) error("Denominator cannot be 0.");
        }

        int get_num(){return num;}
        int get_denom(){return denom;}

        friend bool operator==(Rational& r1, Rational& r2) {
            return r1.get_num() == r2.get_num() && r1.get_denom() == r2.get_denom();
        }

        friend bool operator!=(Rational& r1, Rational& r2) {
            return !(r1 == r2);
        }

		friend Rational operator/(Rational& r1, Rational& r2) { 
			return Rational(r1.num * r2.denom, r1.denom * r2.num); 
        }

        friend Rational operator*(Rational& r1, Rational& r2) {
            return Rational(r1.num * r2.num, r1.denom * r2.denom);
        }

        friend Rational operator+(Rational r1, Rational r2) {
			int lcd = find_lcd(r1.denom, r2.denom);

			r1.num *= lcd / r1.denom;
			r2.num *= lcd / r2.denom;
			r1.denom = r2.denom = lcd;

			r1.num += r2.num;
			return Rational(r1.num, r1.denom);
        }

        friend Rational operator-(Rational r1, Rational r2) {
			int lcd = find_lcd(r1.denom, r2.denom);

			r1.num *= lcd / r1.denom;
			r2.num *= lcd / r2.denom;
			r1.denom = r2.denom = lcd;

			r1.num -= r2.num;
            return Rational(r1.num, r1.denom);
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

	/* 
	Build runs of same numbers
	*/
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
	
//  for (int i = 0; i < runs_a.size(); i++) {
//  	for (int ii = 0; ii < runs_a[i].size(); ii++) {
//  		cout << "runs_a[" << i << "][" << ii << "]:" << runs_a[i][ii] << '\n';
//  	}
//  }
//
//  for (int i = 0; i < runs_b.size(); i++) {
//  	for (int ii = 0; ii < runs_b[i].size(); ii++) {
//  		cout << "runs_b[" << i << "][" << ii << "]:" << runs_b[i][ii] << '\n';
//  	}
//  }

    while (runs_a.size() && runs_b.size()) {
        vector<int> run = runs_a.back();
		bool matched = false;

        runs_a.pop_back();

        for (int i=0; i<runs_b.size(); i++) {
			if (runs_b[i][0] == run[0]) {
				lcd *= run[0] * (runs_b[i].size() > run.size() ? runs_b[i].size() : run.size()); 
				runs_b.erase(runs_b.begin() + i); 
				break;
			}

			if (i == runs_b.size() - 1) { // `run` is the only run of this factor
				lcd *= run[0] * run.size();
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
    cout << find_lcd(10, 12) << '\n';
    cout << find_lcd(12, 31) << '\n';

	Rational r1(3, 5);
	Rational r2(1, 2);

	Rational r3 = r1 * r2;

	cout << r3.get_num() << "/" << r3.get_denom();

    return 0;
}
