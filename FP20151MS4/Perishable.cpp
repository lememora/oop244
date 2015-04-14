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

  void Perishable::unit(const char unit[]) {
    strncpy(_unit, unit, 11);
  }

  void Perishable::expiry(const Date &expiry) {
    _expiry = expiry;
  }

  const char* Perishable::unit() const {
    return _unit;
  }

  Date Perishable::expiry() const {
    return _expiry;
  }

  fstream& Perishable::store(fstream& file) const {
    file << 'P' << ',' << upc() << ',' << name() << ',' << price() << ',' << unit() << ',' << quantity() << ',' << qtyNeeded() << ',' << expiry() << ',' << endl;
    return file;
  }

  fstream& Perishable::load(fstream& file) {
    char sbuf[SBUF_LEN];
    char cbuf;
    double dbuf;
    int ibuf;
    Date datebuf;

    file.getline(sbuf, SBUF_LEN, ',');
    upc(sbuf);
    file.getline(sbuf, SBUF_LEN, ',');
    name(sbuf);
    file >> dbuf >> cbuf;
    price(dbuf);
    file.getline(sbuf, SBUF_LEN, ',');
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
        qtyNeeded();
    } else {
      os <<
        "Upc: "              << upc()       << endl <<
        "Name: "             << name()      << endl <<
        "Price: "            << price()     << endl <<
        "Price after tax: "  << cost()      << endl <<
        "Quantity On Hand: " << quantity()  << endl <<
        "Quantity Needed: "  << qtyNeeded() << endl <<
        "Unit: "             << qtyNeeded() << endl <<
        "Expiry date: "      << qtyNeeded() << endl;
    }
    return os;
  }

  istream& Perishable::conInput(istream& is) {
    char sbuf[256];
    double dbuf;
    int ibuf;
    Date datebuf;

    if (is.fail()==false) {
      _err.clear();
      cout << "Perishable Entry: " << endl;

      cout << "Upc: ";
      is >> sbuf;
      upc(sbuf);

      cout << "Name: ";
      is >> sbuf;
      name(sbuf);

      cout << "Price: ";
      is >> dbuf;
      if (cin.fail()) {
        _err.message("Invalid Price Entry");
      } else {
        price(dbuf);
      }

      if (_err.isClear()) {
        cout << "Quantity On hand: ";
        is >> ibuf;
        if (cin.fail()) {
          _err.message("Invalid Quantity Entry");
        } else {
          quantity(ibuf);
        }
      }

      if (_err.isClear()) {
        cout << "Quantity Needed: ";
        is >> ibuf;
        if (cin.fail()) {
          _err.message("Invalid Quantity Needed Entry");
        } else {
          qtyNeeded(ibuf);
        }
      }

      cout << "Unit: ";
      is >> sbuf;
      upc(sbuf);

      if (_err.isClear()) {

        cout << "Expiry date (YYYY/MM/DD) : ";
        Date datebuf;
        is >> datebuf;

        if (datebuf.bad()) {
          if (_expiry.errCode()==CIN_FAILED) {
            _err.message("Invalid Date Entry");
          } else if (_expiry.errCode()==YEAR_ERROR) {
            _err.message("Invalid Year in Date Entry");
          } else if (_expiry.errCode()==MON_ERROR) {
            _err.message("Invalid Month in Date Entry");
          } else if (_expiry.errCode()==DAY_ERROR) {
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
