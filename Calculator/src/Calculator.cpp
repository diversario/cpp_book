#include "std_lib_facilities.h"

int main() {
    cout << "Expression (+/-): ";

    int lval = 0;
    int rval;

    char op;

    cin >> lval;

    if (!cin) cout << "Missing first operand.";

    while (cin >> op) {
        cin >> rval;

        switch (op) {
            case '+':
                lval += rval;
                break;

            case '-':
                lval -= rval;
                break;

            case '*':
                lval *= rval;
                break;

            case '/':
                lval /= rval;
                break;

            default:
                cout << "Result: " << lval << '\n';
                return 0;
        }
    }

    error("bad expression.");

    return 0;
}
