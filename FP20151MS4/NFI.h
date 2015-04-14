// OOP244 Final Project Milestone 4, 20151
// File NFI.h
// Version 1.0
// Date 2015/04/13
// Author   Rafael Moraes
// Description
// Non-Food Item header file
//
// Revision History
// -----------------------------------------------------------
// Name         Date              Reason
// R.Moraes     2015/04/13        Assignment completion
////////////////////////////////////////////////////////////////

#ifndef __244_NFI_H__
#define __244_NFI_H__

#include "Item.h"
#include "ErrorMessage.h"

#define SBUF_LEN 256

namespace oop244 {

  class NFI : public Item {
  private:
    ErrorMessage _err;
  public:
    NFI();

    std::fstream& store(std::fstream& file) const;
    std::fstream& load(std::fstream& file);
    std::ostream& display(std::ostream& os, bool linear) const;
    std::istream& conInput(std::istream& is);

  };

}
#endif