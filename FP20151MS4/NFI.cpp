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
    char s[MAX_TMPS_LEN];
    char c;
    double d;
    int i;

    file.getline(s, MAX_TMPS_LEN, ',');
    upc(s);
    file.getline(s, MAX_TMPS_LEN, ',');
    name(s);
    file >> d >> c;
    price(d);
    file >> i >> c;
    quantity(i);
    file >> i;
    qtyNeeded(i);
    file.ignore();

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
        "upc: "              << upc()       << endl <<
        "name: "             << name()      << endl <<
        "price: "            << price()     << endl <<
        "Price after tax: "  << cost()      << endl <<
        "Quantity On Hand: " << quantity()  << endl <<
        "Quantity Needed: "  << qtyNeeded() << endl;
    }
    return os;
  }

  istream& NFI::conInput(istream& is) {
    char s[256];
    double d;
    int i;

    if (is.fail()==false) {
      _err.clear();
      cout << "Non-Food Item Entry:" << endl;

      cout << "upc: ";
      is >> s;
      upc(s);

      cout << "name: ";
      is >> s;
      name(s);

      cout << "price: ";
      is >> d;
      if (cin.fail()) {
        _err.message("Invalid Price Entry");
      } else {
        price(d);
      }

      if (_err.isClear()) {
        cout << "Quantity On hand: ";
        is >> i;
        if (cin.fail()) {
          _err.message("Invalid Quantity Entry");
        } else {
          quantity(i);
        }
      }

      if (_err.isClear()) {
        cout << "Quantity Needed: ";
        is >> i;
        if (cin.fail()) {
          _err.message("Invalid Quantity Needed Entry");
        } else {
          qtyNeeded(i);
        }
      }
    }

    return is;
  }

}
