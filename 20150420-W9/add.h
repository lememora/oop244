#ifndef __244_ADD_H__
#define __244_ADD_H__
#include <cstring>
namespace oop244{
  // addTo template for all types goes here
  ??? <??? ???>
  void addTo(???  a, ???   b){
    *a += *b;
  }

  // explicit specialization template for char goes here 
  ????  <>
  void addTo<???>(??? b, ??? a){
    std::strcat(a, b);
  }
}
#endif
