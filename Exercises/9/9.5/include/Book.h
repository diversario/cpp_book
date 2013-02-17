class Book {
public:
    enum Genre {
        fiction=1, nonfiction, periodical, biography, children
    };

    string get_isbn() const {return isbn;};
    string get_title() const {return title;};
    string get_author() const {return author;};
    string get_copyright() const {return copyright;};
    Genre get_genre() const {return genre;};

    bool is_checked_out() const {return checked_out;};
    void check_out();
    void check_in();

    ostream& print(ostream&) const;

    Book(string isbn, string title, string author, string copyright, Genre genre);

    friend bool operator==(Book& b1, Book& b2) {
        return b1.get_isbn() == b2.get_isbn();
    }

    friend bool operator!=(Book& b1, Book& b2) {
        return !(b1 == b2);
    }

    friend ostream& operator<<(ostream& os, const Book& b) {
        return b.print(os);
    }

private:
    string isbn;
    string title;
    string author;
    string copyright;
    Genre genre;

    bool checked_out;
};
