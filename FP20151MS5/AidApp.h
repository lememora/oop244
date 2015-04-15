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
    char _filename[MAX_ISTR_LEN];
    Item* _items[MAX_NO_RECS];
    std::fstream datafile;
    int _noOfItems;

    // copy constructor and assingment operator
    // to prevent copying and assignment
    AidApp(const AidApp& A);
    AidApp& operator=(const AidApp& A);

    // private member fucntions
    int menu();
    void loadRecs();
    void saveRecs();
    void listItems() const;
    int SearchItems(const char* upc) const;
    void updateQty(const char* upc);
    void addItem(bool isPerishable);

  public:
    // constructor and run member function
    AidApp(const char* filename);
    int run();
  };
}

#endif
