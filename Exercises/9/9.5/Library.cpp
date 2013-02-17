#include "include/Library.h"

void Library::add_book(Book& b) {
    books.push_back(b);
}

void Library::add_patron(Patron& p) {
    patrons.push_back(p);
}

bool Library::book_exists(string isbn) const {
    for (int i=0; i<books.size(); i++) {
        if (books[i].get_isbn() == isbn) return true;
    }

    return false;
}

bool Library::patron_exists(int lib_card) const {
    for (int i=0; i<patrons.size(); i++) {
        if (patrons[i].get_lib_card() == lib_card) return true;
    }

    return false;
}

Patron& Library::get_patron(int lib_card) {
    for (int i=0; i<patrons.size(); i++) {
        if (patrons[i].get_lib_card() == lib_card) return patrons[i];
    }

    error("Patron not found.");
}

Book& Library::get_book(string isbn) {
    for (int i=0; i<books.size(); i++) {
        if (books[i].get_isbn() == isbn) return books[i];
    }

    error("Book not found.");
}

void Library::print_transactions() {
    if (!transactions.size()) cout << "<no transactions>.\n";
    else {
        for (int i=0; i<transactions.size(); i++) {
            cout << transactions[i].date.year() << ", " << transactions[i].book.get_title() << ", " << transactions[i].patron.get_lib_card() << ".\n";
        }
    }
}

void Library::checkout_book(string isbn, int lib_card) {
    if (!book_exists(isbn) || !patron_exists(lib_card)) {
        error("Book or patron does not exist.");
    }

    Book& book = get_book(isbn);

    if(book.is_checked_out()) error("Book \"" + book.get_title() + "\" already checked out.");

    Patron& patron = get_patron(lib_card);

    if (patron.if_owns()) error("Patron owns fees.");

    Date date(2012, Date::dec, 27);

    book.check_out();

    Transaction trans(date, book, patron);
    transactions.push_back(trans);
}

vector<Patron> Library::debtors() {
    vector<Patron> p;

    for (int i=0; i<patrons.size(); i++) {
        if (patrons[i].if_owns()) p.push_back(get_patron(patrons[i].get_lib_card()));
    }

    return p;
}
