#ifndef __244_NFI_H__
#define __244_NFI_H__

#include "Item.h"
#include "ErrorMessage.h"

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