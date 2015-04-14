// OOP244 Final Project Milestone 4, 20151
// File NFI.cpp
// Version 1.0
// Date 2015/04/13
// Author   Rafael Moraes
// Description
// Non-Food Item class
//
// Revision History
// -----------------------------------------------------------
// Name         Date              Reason
// R.Moraes     2015/04/13        Assignment completion
////////////////////////////////////////////////////////////////

#include <iomanip>
#include "NFI.h"

using namespace std;

namespace oop244{

  NFI::NFI() : Item("", "", 0, 1) {
  }

  fstream& NFI::store(fstream& file) const {
    file << 'N' << ',' << upc() << ',' << name() << ',' << price() << ',' << quantity() << ',' << qtyNeeded() << endl;
    return file;
  }

  fstream& NFI::load(fstream& file) {
    char sbuf[SBUF_LEN];
    char cbuf;
    double dbuf;
    int ibuf;

    file.getline(sbuf, SBUF_LEN, ',');
    upc(sbuf);
    file.getline(sbuf, SBUF_LEN, ',');
    name(sbuf);
    file >> dbuf >> cbuf;
    price(dbuf);
    file >> ibuf >> cbuf;
    quantity(ibuf);
    file >> ibuf >> cbuf;
    qtyNeeded(ibuf);

    return file;
  }

  ostream& NFI::display(ostream& os, bool linear) const {
    if (_err.isClear()==false) {
      os << _err.message();
    } else if (linear) {
      os <<
        setfill(' ') << left << setw(MAX_UPC_LEN) << upc() << '|' <<
        setw(20) << name() << '|' <<
        right << setw(7) << fixed << showpoint << setprecision(2) << cost() << '|' <<
        setw(4) << quantity() << '|' <<
        setw(4) << qtyNeeded();
    } else {
      os <<
        "Upc: "              << upc()       << endl <<
        "Name: "             << name()      << endl <<
        "Price: "            << price()     << endl <<
        "Price after tax: "  << cost()      << endl <<
        "Quantity On Hand: " << quantity()  << endl <<
        "Quantity Needed: "  << qtyNeeded() << endl;
    }
    return os;
  }

  istream& NFI::conInput(istream& is) {
    char sbuf[256];
    double dbuf;
    int ibuf;

    if (is.fail()==false) {
      _err.clear();
      cout << "Non-Food Item Entry: " << endl;

      cout << "upc: ";
      is >> sbuf;
      upc(sbuf);

      cout << "name: ";
      is >> sbuf;
      name(sbuf);

      cout << "price: ";
      is >> dbuf;
      if (cin.fail()) {
        _err.message("Invalid Price Entry");
      } else {
        price(dbuf);
      }

      if (_err.isClear()) {
        cout << "Quantity on hand: ";
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
    }

    return is;
  }

}