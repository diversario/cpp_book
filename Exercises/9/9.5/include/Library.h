#include "../../std_lib_facilities.h"
#include "Date.h"
#include "Book.h"
#include "Patron.h"

class Library {
private:
    struct Transaction {
        Transaction(Date d, Book b, Patron p)
            : date(d), book(b), patron(p) {}

        Date date;
        Book book;
        Patron patron;
    };

    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;

public:
    void add_book(Book&);
    void add_patron(Patron&);
    void checkout_book(string isbn, int lib_card);

    bool book_exists(string isbn) const;
    bool patron_exists(int lib_card) const;

    Patron& get_patron(int);
    Book& get_book(string);

    class Invalid{};

    vector<Patron> debtors();

    void print_transactions();
};
