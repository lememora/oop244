#include <fstream>
#include "Perishable.h"

using namespace std;

namespace oop244 {

  Perishable::Perishable() : Item("", "", 0, 1, false) {
    unit("");
  }

  void Perishable::unit(const char unit_[]) {
    if (unit_) {
      strncpy(_unit, unit_, 11);
    }
    if (strlen(unit_) >= 11) {
      _unit[10] = '\0';
    }
  }

  void Perishable::expiry(const Date expiry_) {
    _expiry = expiry_;
  }

  const char* Perishable::unit() const {
    return _unit;
  }

  Date Perishable::expiry() const {
    return _expiry;
  }

  fstream& Perishable::store(fstream& file) const {
    return file;
  }

  fstream& Perishable::load(fstream& file) {
    return file;
  }

  ostream& Perishable::display(ostream& os, bool linear) const {
    return os;
  }

  istream& Perishable::conInput(istream& is) {
    return is;
  }

}
