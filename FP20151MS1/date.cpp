#include "date.h"
#include "general.h"
#include <iomanip>
#include <iostream>

using namespace std;

namespace oop244 {
  // returns a uniqe value out of date
  // this value is used to compare two dates
  int Date::value() const {
    return _year * 372 + _mon * 31 + _day;
  }

  // validate function
  void Date::validate() {
    if (_year < MIN_YEAR || _year > MAX_YEAR) {
      _readErrorCode = YEAR_ERROR;
    }
    if (_mon < 1 || _mon > 12) {
      _readErrorCode = MON_ERROR;
    }
    if (_day < 1 || _day > mdays()) {
      _readErrorCode = DAY_ERROR;
    }
  }

  // returns the day of the month.
  // _mon value must be set for this to work
  // if _mon is invalid, this function returns -1
  // leap years are considered in this logic

  int Date::mdays() const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = _mon >= 1 && _mon <= 12 ? _mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
  }

  // constructors

  Date::Date() {
    _year = 0;
    _mon = 0;
    _day = 0;
    _readErrorCode = NO_ERROR;
  }

  Date::Date(int year, int month, int day) {
    _year = year;
    _mon = month;
    _day = day;
    _readErrorCode = NO_ERROR;
    validate();
  }

  // member fucntions

  bool Date::bad() const {
    return _readErrorCode != NO_ERROR;
  }

  int Date::errCode() const {
    return _readErrorCode;
  }

  // operators

  bool Date::operator==(const Date& D) const {
    return this->value() == D.value();
  }

  bool Date::operator!=(const Date& D) const {
    return this->value() != D.value();
  }

  bool Date::operator<(const Date& D) const {
    return this->value() < D.value();
  }

  bool Date::operator>(const Date& D) const {
    return this->value() > D.value();
  }

  bool Date::operator<=(const Date& D) const {
    return this->value() <= D.value();
  }

  bool Date::operator>=(const Date& D) const {
    return this->value() >= D.value();
  }

  // IO funtions

  std::istream& Date::read(std::istream& istr) {
    char buffer[11];
    istr.getline(buffer, 11, '\0');
    sscanf(buffer, "%d/%d/%d", &_year, &_mon, &_day);
    validate();
    return istr;
  }

  std::ostream& Date::write(std::ostream& ostr) const {
    return ostr << std::setw(4) << std::setfill('0') << _year << '/'
                << std::setw(2) << std::setfill('0') << _mon  << '/'
                << std::setw(2) << std::setfill('0') << _day;
  }

  // non-memeber operator overloads

  std::ostream& operator<<(std::ostream& os, const Date& D) {
    return D.write(os);
  }

  std::istream& operator>>(std::istream& is, Date& D) {
    return D.read(is);
  }

}
