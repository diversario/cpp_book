#include "../std_lib_facilities.h"
#include "include/Book.h"

Book::Book(string isbn_, string title_, string author_, string copyright_, Genre genre_)
    : isbn(isbn_), title(title_), author(author_), copyright(copyright_), genre(Genre(genre_))
    , checked_out(false)
{
    int isbn_blocks = 0;

    for(int i=0; i<isbn.size(); i++) {
        if (isbn_blocks<3) {
            if (isdigit(isbn[i])) continue;
            else if (isbn[i] == '-') {
                isbn_blocks++;
            } else if (isalpha(isbn[i])) {
                error("Invalid ISBN.");
            }
        } else {
            if (!isdigit(isbn[i]) && !isalpha(isbn[i])) error("Invalid ISBN.");
        }

        if (i-1 == isbn.size() && isbn_blocks-1 != isbn.size()) error("Invalid ISBN.");
    }

    if (title.size() == 0) error("Missing title.");
    if (author.size() == 0) error("Missing author.");
    if (copyright.size() == 0) error("Missing copyright.");
}

ostream& Book::print(ostream& os) const {
    cout << "Title: " << get_title() << '\n'
         << "Author: " << get_author() << '\n'
         << "Genre: " << get_genre() << '\n'
         << "ISBN: " << get_isbn() << '\n';

    return os;
}

void Book::check_out() {
    checked_out = true;
}

void Book::check_in() {
    checked_out = false;
}

