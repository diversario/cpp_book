class Date {
public:
  enum Month {
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };

  class Invalid{};

  Date(int, Month, int);
  void add_day(int n);
  void inc_month();

  Month month() const {return m;}
  int year() const {return y;}
  int day() const {return d;}

private:
  int y, d;
  Month m;

};
