// OOP244 Final Project Milestone 3, 20152
// File Streamable.h
// Version 1.0
// Date 2015/04/04
// Author   Rafael Moraes
// Description
// Streamable header
//
// Revision History
// -----------------------------------------------------------
// Name         Streamable        Reason
// R.Moraes     2015/04/04        Assignment completion
////////////////////////////////////////////////////////////////
#ifndef __244__Streamable__
#define __244__Streamable__
// hearfile includes:
#include <fstream>
#include <iostream>

namespace oop244{
  class Streamable{
  public:
    // pure virutal methods:

    virtual std::fstream& store(std::fstream& file) const =0;
    virtual std::fstream& load(std::fstream& file) =0;
    virtual std::ostream& display(std::ostream& os, bool linear) const =0;
    virtual std::istream& conInput(std::istream& is) =0;

    // virutal destructor:

    virtual ~Streamable();

  };
  // Non-memenber operator overoad prototypes for cin and cout:

  std::ostream& operator<<(std::ostream& os, const Streamable& D);
  std::istream& operator>>(std::istream& is, Streamable& D);

}
#endif