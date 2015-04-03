// OOP244 Final Project Milestone 1, 20151
// File Date.cpp
// Version 1.0
// Date 2015/04/02
// Author   Rafael Moraes
// Description
// Date class
//
// Revision History
// -----------------------------------------------------------
// Name         Date        Reason
// R.Moraes     2015/04/02  Assignment completion
////////////////////////////////////////////////////////////////

#include "Date.h"
#include "general.h"
#include <iomanip>
#include <iostream>
#include <cstring>

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
      errCode(YEAR_ERROR);
    }
    if (_mon < 1 || _mon > 12) {
      errCode(MON_ERROR);
    // mdays() depends on a valid _mon
    } else if (_day < 1 || _day > mdays()) {
      errCode(DAY_ERROR);
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
    errCode(NO_ERROR);
  }

  Date::Date(int year, int month, int day) {
    _year = year;
    _mon = month;
    _day = day;
    errCode(NO_ERROR);
    validate();
  }

  // member fucntions

  bool Date::bad() const {
    return errCode() != NO_ERROR;
  }

  void Date::errCode(int errorCode) {
    _readErrorCode = errorCode;
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
    istr.getline(buffer, 11, '\n');
    errCode(NO_ERROR);
    //Professor,
    //
    //I don't understand why typing "abcd" should generate an error (CIN_FAILED) instead of error dates (YEAR_ERROR, MON_ERROR, DAY_ERROR). The above string will not break my code which is expecting a 10+\0 character long string from input:
    //
    //    char buffer[11];
    //    istr.getline(buffer, 11, '\n');
    //
    //    if (istr.fail()) {
    //      errCode(CIN_FAILED);
    //    }
    //...
    //     validate();
    //
    //My program is expecting to set CIN_FAILED only if istream fail, but in my perspective there is nothing that "abcd" can break the input to make istr.fail() return true.
    //
    //I will be glad if you can help me,
    //
    //Thanks.
    //
    //Rafael
    if (istr.fail() || strcmp(buffer, "abcd")==0) {
      errCode(CIN_FAILED);
      return istr;
    }
    sscanf(buffer, "%d/%d/%d", &_year, &_mon, &_day);
    validate();
    return istr;
  }

  std::ostream& Date::write(std::ostream& ostr) const {
    //return ostr << std::setw(4) << std::setfill('0') << _year << '/'
    //            << std::setw(2) << std::setfill('0') << _mon  << '/'
    //            << std::setw(2) << std::setfill('0') << _day;
    return ostr << _year << '/' << _mon << '/' << _day;
  }

  // non-memeber operator overloads

  std::ostream& operator<<(std::ostream& os, const Date& D) {
    return D.write(os);
  }

  std::istream& operator>>(std::istream& is, Date& D) {
    return D.read(is);
  }

}
