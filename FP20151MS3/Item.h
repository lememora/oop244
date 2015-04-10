// OOP244 Final Project Milestone 3, 20152
// File Item.h
// Version 1.0
// Date 2015/04/10
// Author   Rafael Moraes
// Description
// Item header file
//
// Revision History
// -----------------------------------------------------------
// Name         Streamable        Reason
// R.Moraes     2015/04/10        Assignment completion
////////////////////////////////////////////////////////////////

#ifndef __244_ITEM__
#define __244_ITEM__

// header file includes
#include "Streamable.h"
#include "general.h"

namespace oop244 {

  class Item : public Streamable {
  private:
    char _upc[MAX_UPC_LEN + 1];
    char* _name;
    double _price;
    bool _taxed;
    int _quantity;
    int _qtyNeeded;

  public:
    // constructors
    Item(const char upc[], const char* name, double price, int qtyNeeded, bool taxed=true);
    Item(const Item& I);

    // destructor
    ~Item();

    // setters
    void upc(char upc[]);
    void price(double price);
    void name(char* name);
    void taxed(bool taxed);
    void quantity(int quantity);
    void qtyNeeded(int qtyNeeded);

    // getters
    const char* upc() const;
    double price() const;
    const char* name() const;
    bool taxed() const;
    int quantity() const;
    int qtyNeeded() const;

    double cost() const;

    // operators
    Item& operator=(const Item& I);
    bool operator==(const char* upc);
    int operator+=(int n);
  };

  // Non-member operator overload prototype
  double operator+=(double& d, const Item& I);
}

#endif
