// OOP244 Final Project Milestone 3, 20152
// File Streamable.cpp
// Version 1.0
// Date 2015/04/04
// Author   Rafael Moraes
// Description
// Streamable class
//
// Revision History
// -----------------------------------------------------------
// Name         Streamable        Reason
// R.Moraes     2015/04/04        Assignment completion
////////////////////////////////////////////////////////////////
#include "Streamable.h"
namespace oop244{
  // destructor:

  Streamable::~Streamable() { }

  // Non-memenber operator overoad implementation for cin and cout:

  std::ostream& operator<<(std::ostream& os, const Streamable& S) {
    return S.display(os, true);
  }

  std::istream& operator>>(std::istream& is, Streamable& S) {
    return S.conInput(is);
  }

}