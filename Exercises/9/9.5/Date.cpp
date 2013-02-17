#include "include/Date.h"

Date::Date(int yy, Date::Month mm, int dd) {
  if (yy > 0 && mm <=12 && mm >= 1 && dd >= 1 && dd <= 31) {
    d = dd;
    m = mm;
    y = yy;
  } else {
    throw Date::Invalid();
  }
}

void Date::add_day(int n) {
  if (d + n > 31) {
    m = Month(m + 1);
  }
  d += n;
}

Date::Month operator++(Date::Month& m) {
  m = m == Date::dec ? Date::jan : Date::Month(m+1);
}

void Date::inc_month() {
  ++m;
}
