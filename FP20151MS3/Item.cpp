// OOP244 Final Project Milestone 3, 20152
// File Item.cpp
// Version 1.0
// Date 2015/04/11
// Author   Rafael Moraes
// Description
// Item class
//
// Revision History
// -----------------------------------------------------------
// Name         Streamable        Reason
// R.Moraes     2015/04/11        Assignment completion
////////////////////////////////////////////////////////////////

// header file includes
#include "Item.h"
#include <cstring>
#define BLANK ((char*)0)

using namespace std;

namespace oop244 {

  void Item::allocate(int size) {
    deallocate();
    _name = new (nothrow) char[size];
  }
  void Item::deallocate() {
    if (_name != BLANK){
      delete[] _name;
      _name = BLANK;
    }
  }

  // constructors
  Item::Item(const char upc_[], const char* name_, double price_, int qtyNeeded_, bool taxed_) : _name(BLANK) {
    upc(upc_);
    name(name_);
    _quantity = 0;
    _price = price_;
    _qtyNeeded = qtyNeeded_;
    _taxed = taxed_;
  }

  Item::Item(const Item& I) : _name(BLANK) {
    *this = I;
  }

  Item& Item::operator=(const Item& I) {
    if (this != &I) {
      upc(I._upc);
      name(I._name);
      _quantity = I._quantity;
      _price = I._price;
      _qtyNeeded = I._qtyNeeded;
      _taxed = I._taxed;
    }
    return *this;
  }

  void Item::upc(const char upc[]) {
    if (upc) {
      strncpy(_upc, upc, MAX_UPC_LEN);
    }
    if (strlen(upc) >= MAX_UPC_LEN) {
      _upc[MAX_UPC_LEN] = '\0';
    }
  }

  void Item::price(double price) {
    _price = price;
  }

  void Item::name(const char* name) {
    allocate(strlen(name) + 1);
    strcpy(_name, name);
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

  double Item::price() const {
    return _price;
  }

  const char* Item::name() const {
    return _name;
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
      cost*= TAX+1;
    }
    return cost;
  }

  // operator overloads
  bool Item::operator==(const char* upc) {
    return strcmp(_upc, upc)==0;
  }

  int Item::operator+=(int n) {
    return _quantity+=n;
  }

  double operator+=(double &n, const Item& I) {
    return n+=(I.cost() * I.quantity());
  }

  // destructor
  Item::~Item() {
    deallocate();
  }

}
