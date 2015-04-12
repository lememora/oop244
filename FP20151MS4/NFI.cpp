#include <NFI.h>

using namespace std;

namespace oop244{

  NFI::NFI() : Item("", "", 0, 1) {
  }

  fstream& NFI::store(fstream& file) const {
    return file;
  }

  fstream& NFI::load(fstream& file) {
    return file;
  }

  ostream& NFI::display(ostream& os, bool linear) const {
    return os;
  }

  istream& NFI::conInput(istream& is) {
    return is;
  }

}