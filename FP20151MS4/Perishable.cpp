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
    char sbuf[MAX_SBUF_LEN];
    char cbuf;
    double dbuf;
    int ibuf;
    Date datebuf;

    file.getline(sbuf, MAX_SBUF_LEN, ',');
    upc(sbuf);
    file.getline(sbuf, MAX_SBUF_LEN, ',');
    name(sbuf);
    file >> dbuf >> cbuf;
    price(dbuf);
    file.getline(sbuf, MAX_SBUF_LEN, ',');
    unit(sbuf);
    file >> ibuf >> cbuf;
    quantity(ibuf);
    file >> ibuf >> cbuf;
    qtyNeeded(ibuf);
    file >> datebuf >> cbuf;
    expiry(datebuf);

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
        "Quantity On Hand: " << quantity()  << endl <<
        "Quantity Needed: "  << qtyNeeded() << endl <<
        "Unit: "             << unit()      << endl <<
        "Expiry date: "      << expiry()    << endl;
    }
    return os;
  }

  istream& Perishable::conInput(istream& is) {
    char sbuf[MAX_SBUF_LEN];
    double dbuf;
    int ibuf;
    // Date datebuf;

    if (is.fail()==false) {

      _err.clear();
      cout << "Perishable Entry: " << endl;

      cout << "upc: ";
      is >> sbuf;
      if (is.fail()==false) {
        upc(sbuf);
      }

      cout << "name: ";
      is >> sbuf;
      if (is.fail()==false) {
        name(sbuf);
      }

      cout << "price: ";
      is >> dbuf;
      if (is.fail()) {
        _err.message("Invalid Price Entry");
      } else {
        price(dbuf);
      }

      if (_err.isClear()) {
        cout << "Quantity on hand: ";
        is >> ibuf;
        if (is.fail()) {
          _err.message("Invalid Quantity Entry");
        } else {
          quantity(ibuf);
        }
      }

      if (_err.isClear()) {
        cout << "Quantity needed: ";
        is >> ibuf;
        if (is.fail()) {
          _err.message("Invalid Quantity Needed Entry");
        } else {
          qtyNeeded(ibuf);
        }
      }

      if (_err.isClear()) {

        cout << "Unit: ";
        is >> sbuf;
        unit(sbuf);

        cout << "Expiry date: ";
        Date datebuf;
        is >> datebuf;

        if (datebuf.bad()) {
          if (datebuf.errCode()==CIN_FAILED) {
            _err.message("Invalid Date Entry");
          } else if (datebuf.errCode()==YEAR_ERROR) {
            _err.message("Invalid Year in Date Entry");
          } else if (datebuf.errCode()==MON_ERROR) {
            _err.message("Invalid Month in Date Entry");
          } else if (datebuf.errCode()==DAY_ERROR) {
            _err.message("Invalid Day in Date Entry");
          }
          is.setstate(ios::failbit);
        } else {
          expiry(datebuf);
        }
      }
    }

    return is;
  }

}
