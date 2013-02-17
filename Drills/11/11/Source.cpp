#include "../../std_lib_facilities.h"

void print_row(string lname, string fname, string phone, string email) {
    cout << setw(10) << lname
         << setw(14) << fname
         << setw(14) << phone
         << setw(32) << email
         << endl;
}

int main () {
    int birth_year = 1983;

    cout << setw(8) << "base\t" << setw(8) << '|' << setw(8) << "value" << endl
         << dec << setw(8) << "dec" << setw(8) << '|' << setw(8) << birth_year << endl
         << hex << setw(8) << "hex" << setw(8) << '|' << setw(8) << birth_year << endl
         << oct << setw(8) << "oct" << setw(8) << '|' << setw(8) << birth_year << endl
    ;

    cout << "base\t" << "|\t" << "value" << endl
        << showbase
        << dec << "dec\t" << "|\t" << birth_year << endl
        << hex << "hex\t" << "|\t" << birth_year << endl
        << oct << "oct\t" << "|\t" << birth_year << endl
        ;

    cout << dec << 29 << endl;
    /*
    cout << "enter shit:" << endl;

    int a, b, c, d;

    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << endl;
    */
    double num = 1234567.89;

    cout << general << num << endl
         << fixed << num << endl
         << scientific << setprecision(8) << num << endl
         ;

    print_row("Ilya", "Shaisultanov", "617-309-8520", "ilya.shaisultanov@gmail.com");
    print_row("Rinat", "Ussenov", "617-959-3910", "rinat.ussenov@gmail.com");
    print_row("Gregory", "Langlais", "617-xxx-xxxx", "gregory.langlais.1@gmail.com");
    print_row("Sergey", "Shatzkiy", "75-35-39", "stabidum@gmail.com");
    print_row("Boris", "Ananyev", "45678654356", "boris.ananyev@gmail.com");

    keep_window_open();

    return 0;
}