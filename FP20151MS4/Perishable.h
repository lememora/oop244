#ifndef __244_Perishable_H__
#define __244_Perishable_H__

#include "Date.h"
#include "Item.h"
#include "ErrorMessage.h"

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

    void unit(const char unit_[]);
    void expiry(const Date expiry_);

    const char* unit() const;
    Date expiry() const;

  };
}


#endif
