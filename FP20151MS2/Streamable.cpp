#include <iostream>
#include "Streamable.h"
namespace oop244{
  // destructor:

  Streamable::~Streamable() { }

  std::fstream& Streamable::Store(std::fstream& file) const {
    return file;
  }

  std::fstream& Streamable::Load(std::fstream& file) const {
    return file;
  }

  std::ostream& Streamable::display(std::ostream& os, bool linear) const {
    return os;
  }

  std::istream& Streamable::conInput(std::istream& is) const {
    return is;
  }


  // Non-memenber operator overoad implementation for cin and cout:

  std::ostream& operator<<(std::ostream& os, const Streamable& S) {
    // return S.Store(os);
    return os;
  }

  std::istream& operator>>(std::istream& is, Streamable& S) {
    // return S.Load(is);
    return is;
  }

}