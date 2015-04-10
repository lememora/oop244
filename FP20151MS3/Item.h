#ifndef __244_ITEM__
#define __244_ITEM__

// header file includes

namespace oop244 {

  class Item : public Streamable {
  private:
    char _upc[MAX_UPC_LEN+1];
    char *_name;
    double _price;
    int _taxed;
    int _quantity;
    int _qtyNeeded;

  public:
    // constructors
    Item(char[] upc, char* name, double price, int quantity, int taxed);

    // destructor


    // setters








    // getters







    // operators



  };
  // Non-member operator overload prototype
  double operator+=(double& d, const Item& I);
}


#endif