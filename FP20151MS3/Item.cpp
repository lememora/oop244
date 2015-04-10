// OOP244 Final Project Milestone 3, 20152
// File Item.cpp
// Version 1.0
// Date 2015/04/10
// Author   Rafael Moraes
// Description
// Item class
//
// Revision History
// -----------------------------------------------------------
// Name         Streamable        Reason
// R.Moraes     2015/04/10        Assignment completion
////////////////////////////////////////////////////////////////

// header file includes
#include "Item.h"

using namespace std;

namespace oop244 {

  // constructors
  Item::Item(const char upc[], const char* name, double price, int qtyNeeded, bool taxed) {
    strncpy(_upc, upc, MAX_UPC_LEN);

    if (_name){
      delete[] _name;
      _name = (char*)0;
    }
    _name = new (nothrow) char[strlen(name)];
    strncpy(_name, name, strlen(name));

    _price = price;
    _qtyNeeded = qtyNeeded;
    _taxed = taxed;

    _quantity = 0;
  }

  Item::Item(const Item& I) {
    *this = I;
  }

  Item& Item::operator=(const Item& I) {
    if (this != &I) {
      strcpy(_upc, I._upc);
      _quantity = I._quantity;
      _price = I._price;
      _qtyNeeded = I._qtyNeeded;
      _taxed = I._taxed;

      if (_name){
        delete[] _name;
        _name = (char*)0;
      }

      _name = new (nothrow) char[strlen(I._name)];
      strncpy(_name, I._name, strlen(I._name));
    }
    return *this;
  }

  void Item::upc(char upc[]) {
    if (upc) {
      strncpy(_upc, upc, MAX_UPC_LEN);
    }
  }

  void Item::name(char* name) {
    if (_name){
      delete[] _name;
      _name = (char*)0;
    }
    _name = new (nothrow) char[strlen(name)];
    strncpy(_name, name, strlen(name));
  }

  void Item::price(double price) {
    _price = price;
  }

  void Item::taxed(bool taxed) {
    _taxed = taxed;
  }

  void Item::quantity(int quantity) {
    _quantity = quantity;
  }

  void Item::qtyNeeded(int qtyNeeded) {
    _qtyNeeded = qtyNeeded;
  }

  const char* Item::upc() const {
    return _upc;
  }

  const char* Item::name() const {
    return _name;
  }

  double Item::price() const {
    return _price;
  }

  bool Item::taxed() const {
    return _taxed;
  }

  int Item::quantity() const {
    return _quantity;
  }

  int Item::qtyNeeded() const {
    return _qtyNeeded;
  }

  double Item::cost() const {
    double cost = _price;
    if (_taxed) {
      cost*= TAX + 1;
    }
    return cost;
  }

  // operator overloads
  bool Item::operator==(const char* upc) {
    return strcmp(upc, _upc)==0;
  }

  int Item::operator+=(int n) {
    return _quantity+=n;
  }

  double operator+=(double &n, const Item& I) {
    return n+=(I.cost() * I.quantity());
  }

  // destructor
  Item::~Item() {
    if (_name) {
      delete[] _name;
      _name = (char*)0;
    }
  }

}
