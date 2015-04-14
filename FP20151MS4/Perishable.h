// OOP244 Final Project Milestone 4, 20151
// File Perishable.h
// Version 1.0
// Date 2015/04/13
// Author   Rafael Moraes
// Description
// Perishable header file
//
// Revision History
// -----------------------------------------------------------
// Name         Date              Reason
// R.Moraes     2015/04/13        Assignment completion
////////////////////////////////////////////////////////////////

#ifndef __244_Perishable_H__
#define __244_Perishable_H__

#include "Date.h"
#include "Item.h"
#include "ErrorMessage.h"

#define SBUF_LEN 256

namespace oop244 {

  class Perishable : public Item {
  private:
    ErrorMessage _err;
    char _unit[11];
    Date _expiry;

  public:
    Perishable();

    std::fstream& store(std::fstream& file) const;
    std::fstream& load(std::fstream& file);
    std::ostream& display(std::ostream& os, bool linear) const;
    std::istream& conInput(std::istream& is);

    void unit(const char unit[]);
    void expiry(const Date &expiry);

    const char* unit() const;
    Date expiry() const;
  };

}

#endif
