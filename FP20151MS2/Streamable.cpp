#include <fstream>
#include <iostream>
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