#include "../std_lib_facilities.h"
#include "include/Library.h"

int main() {
    Book b1("1-1-1-a", "Book 1", "Author 1", "2012", Book::fiction);
    Book b2("1-1-1-b", "Book 2", "Author 2", "2012", Book::periodical);
    Book b3("1-1-1-c", "Book 3", "Author 3", "2012", Book::nonfiction);

    Patron p1("Patron 1", 1, 0);
    Patron p2("Patron 2", 2, 0);
    Patron p3("Patron 3", 3, 22.1);

    Library lib;

    lib.add_book(b1);
    lib.add_book(b2);
    lib.add_book(b3);

    lib.add_patron(p1);
    lib.add_patron(p2);
    lib.add_patron(p3);

    cout << "Transactions before:\n";
    lib.print_transactions();

    lib.checkout_book("1-1-1-a", 1);
    lib.checkout_book("1-1-1-b", 2);

    try {
        lib.checkout_book("1-1-1-c", 3);
    } catch (runtime_error e) {
        cout << "\nERROR: " << e.what() << " @29\n";
    }

    try {
        lib.checkout_book("1-1-1-b", 1);
    } catch (runtime_error e) {
        cout << "\nERROR: " <<  e.what() << " @35\n";
    }

    cout << "\nTransactions after 2 books:\n";
    lib.print_transactions();

    vector<Patron> debtors = lib.debtors();

    cout << "\nDebtors before:\n";
    for (int i=0; i<debtors.size(); i++) {
        cout << debtors[i];
    }

    Patron& p33 = lib.get_patron(3);
    p33.set_fee(0);

    lib.checkout_book("1-1-1-c", 3);

    cout << "\nDebtors after:\n";
    debtors = lib.debtors();
    for (int i=0; i<debtors.size(); i++) {
        cout << debtors[i];
    }

    cout << "\nTransactions after 3 books:\n";
    lib.print_transactions();

    return 0;
}
