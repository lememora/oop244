// OOP244 Final Project Milestone 4, 20151
// File Perishable.cpp
// Version 1.0
// Date 2015/04/13
// Author   Rafael Moraes
// Description
// Perishable class
//
// Revision History
// -----------------------------------------------------------
// Name         Date              Reason
// R.Moraes     2015/04/13        Assignment completion
////////////////////////////////////////////////////////////////

#include <fstream>
#include <cstring>
#include <iomanip>
#include "Perishable.h"

using namespace std;

namespace oop244 {

  Perishable::Perishable() : Item("", "", 0, 1, false) {
    unit("");
  }

  void Perishable::unit(const char __unit[]) {
    if (__unit) {
      strncpy(_unit, __unit, MAX_UNIT_LEN);
      if (strlen(__unit) > MAX_UNIT_LEN) {
        _unit[MAX_UNIT_LEN] = 0;
      }
    }
  }

  void Perishable::expiry(const Date &__expiry) {
    _expiry = __expiry;
  }

  const char* Perishable::unit() const {
    return _unit;
  }

  Date Perishable::expiry() const {
    return _expiry;
  }

  fstream& Perishable::store(fstream& file) const {
    file << 'P' << ',' << upc() << ',' << name() << ',' << price() << ',' << unit() << ',' << quantity() << ',' << qtyNeeded() << ',' << expiry() << endl;
    return file;
  }

  fstream& Perishable::load(fstream& file) {
    char s[MAX_TMPS_LEN];
    char c;
    double d;
    int i;
    Date dt;

    file.getline(s, MAX_TMPS_LEN, ',');
    upc(s);
    file.getline(s, MAX_TMPS_LEN, ',');
    name(s);
    file >> d >> c;
    price(d);
    file.getline(s, MAX_TMPS_LEN, ',');
    unit(s);
    file >> i >> c;
    quantity(i);
    file >> i >> c;
    qtyNeeded(i);
    file >> dt;
    expiry(dt);
    file.ignore();

    return file;
  }

  ostream& Perishable::display(ostream& os, bool linear) const {
    if (_err.isClear()==false) {
      os << _err.message();
    } else if (linear) {
      os <<
        setfill(' ') << left << setw(MAX_UPC_LEN) << upc() << '|' <<
        setw(20) << name() << '|' <<
        right << setw(7) << fixed << showpoint << setprecision(2) << cost() << '|' <<
        setw(4) << quantity() << '|' <<
        setw(4) << qtyNeeded() << '|' <<
        left << setw(10) << unit() << '|' <<
        expiry();
    } else {
      os <<
        "Upc: "              << upc()       << endl <<
        "Name: "             << name()      << endl <<
        "Price: "            << price()     << endl <<
        "Price after tax: "  << cost()      << endl <<
        "Quantity On hand: " << quantity()  << endl <<
        "Quantity Needed: "  << qtyNeeded() << endl <<
        "Unit: "             << unit()      << endl <<
        "Expiry date: "      << expiry()    << endl;
    }
    return os;
  }

  istream& Perishable::conInput(istream& is) {
    char s[MAX_TMPS_LEN];
    double d;
    int i;
    Date dt;

    if (is.fail()==false) {

      _err.clear();
      cout << "Perishable Item Entry: " << endl;

      cout << "Upc: ";
      is >> s;
      if (is.fail()==false) {
        upc(s);
      }

      cout << "Name: ";
      is >> s;
      if (is.fail()==false) {
        name(s);
      }

      cout << "Price: ";
      is >> d;
      if (is.fail()) {
        _err.message("Invalid Price Entry");
      } else {
        price(d);
      }

      if (_err.isClear()) {
        cout << "Quantity On hand: ";
        is >> i;
        if (is.fail()) {
          _err.message("Invalid Quantity Entry");
        } else {
          quantity(i);
        }
      }

      if (_err.isClear()) {
        cout << "Quantity Needed: ";
        is >> i;
        if (is.fail()) {
          _err.message("Invalid Quantity Needed Entry");
        } else {
          qtyNeeded(i);
        }
      }

      if (_err.isClear()) {

        cout << "Unit: ";
        is >> s;
        unit(s);

        cout << "Expiry date (YYYY/MM/DD) : ";
        is >> dt;

        if (dt.bad()) {
          if (dt.errCode()==CIN_FAILED) {
            _err.message("Invalid Date Entry");
          } else if (dt.errCode()==YEAR_ERROR) {
            _err.message("Invalid Year in Date Entry");
          } else if (dt.errCode()==MON_ERROR) {
            _err.message("Invalid Month in Date Entry");
          } else if (dt.errCode()==DAY_ERROR) {
            _err.message("Invalid Day in Date Entry");
          }
          is.setstate(ios::failbit);
        } else {
          expiry(dt);
        }
      }
    }

    return is;
  }

}
