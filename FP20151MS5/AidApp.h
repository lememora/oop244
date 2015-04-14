// OOP244 Final Project Milestone 5, 20151
// File AidApp.h
// Version 1.0
// Date 2015/04/14
// Author   Rafael Moraes
// Description
// AidApp header file
//
// Revision History
// -----------------------------------------------------------
// Name         Streamable        Reason
// R.Moraes     2015/04/14        Assignment completion
////////////////////////////////////////////////////////////////

#ifndef __244_AIDAPP_H__
#define __244_AIDAPP_H__
#include "Perishable.h"
#include "NFI.h"

namespace oop244 {

  class AidApp {
    // private member arguments
    char _filename[256];
    Item* _items[MAX_NO_RECS];
    std::fstream datafile;
    int _noOfItems;

    // copy constructor and assingment operator
    // to prevent copying and assignment
    AidApp(const AidApp& A);
    AidApp& operator=(const AidApp& A);

    // private member fucntions



  public:
    // constructor and run member function
    AidApp(const char* filenamex);
    int menu();
    void listItems() const;
    void saveRecs();
    void loadRecs();
    void updateQty(const char* UPC);
    int SearchItems(const char* upc) const;
    void addItem(bool isPerishable);
    int run();
  };
}

#endif
