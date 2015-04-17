// OOP244 Final Project Milestone 5, 20151
// File AidApp.cpp
// Version 1.0
// Date 2015/04/14
// Author   Rafael Moraes
// Description
// AidApp class
//
// Revision History
// -----------------------------------------------------------
// Name         Streamable        Reason
// R.Moraes     2015/04/14        Assignment completion
////////////////////////////////////////////////////////////////

#include <cstring>
#include <new>
#include <iomanip>
#include "AidApp.h"

using namespace std;

namespace oop244 {

  // copy constructor and assignment operator
  AidApp::AidApp(const AidApp& A) {}
  AidApp& AidApp::operator=(const AidApp& A) {
    return *this;
  }

  // constructor
  // copies filename to _filename
  // sets all the _items to null
  // sets _noOfItems to null
  // loads the Records
  AidApp::AidApp(const char* filename) {
    if (filename) {
      strncpy(_filename, filename, MAX_ISTR_LEN);
      if (strlen(filename) >= MAX_ISTR_LEN) {
        _filename[MAX_ISTR_LEN-1] = 0;
      }

      _noOfItems = MAX_NO_RECS-1;
      do {
        _items[_noOfItems] = 0;
      } while (_noOfItems-- > 0);

      loadRecs();
    }
  }

  // Menu() displays the menu as follows and waits for the user to
  // select an option.
  // if the selection is valid, it will return the selection
  // if not it will return -1
  // this funtion makes sure there is no characters left in keyboard
  // and wipes it before exit.
  int AidApp::menu() {
    unsigned short n;
    cout <<
      "Disaster Aid Supply Management Program" << endl <<
      "1 - List items" << endl <<
      "2 - Add Non-food item Item" << endl <<
      "3 - Add Perishable item" << endl <<
      "4 - Update item quantity" << endl <<
      "0 - exit program" << endl <<
      "> ";
    return (cin >> n && !cin.fail() && n < 5) ? n : -1;
  }


  // lists all the items in linear format on the screen

  void AidApp::listItems() const {
    cout <<
      left  << setfill(' ') << setw(6)  << "Row" << "|" <<
      left  << setfill(' ') << setw(8)  << "UPC" << "|" <<
      left  << setfill(' ') << setw(20) << "Item Name" << "|" <<
      left  << setfill(' ') << setw(7)  << "Cost" << "|" <<
      right << setfill(' ') << setw(4)  << "QTY" << "|" <<
      right << setfill(' ') << setw(4)  << "Need" << "|" <<
      left  << setfill(' ') << setw(10) << "Unit" << "|" <<
      right << setfill(' ') << setw(10) << "Expiry" <<
      endl  <<
      left  << setfill('-') <<
      left  << setfill(' ') << setw(5)  << "|-" <<
      left  << setfill(' ') << setw(7)  << "|-" <<
      left  << setfill(' ') << setw(19) << "|-" <<
      left  << setfill(' ') << setw(6)  << "|" <<
      right << setfill(' ') << setw(4)  << "|" <<
      left  << setfill(' ') << setw(4)  << "|-" <<
      left  << setfill(' ') << setw(9)  << "|-" <<
      left  << setfill(' ') << setw(9)  << endl;
  }


  // opens the file for writing
  // stores the items in the file
  // closes the file
  void AidApp::saveRecs() {
    int c = 0;
    datafile.open(_filename, ios::out);
    do {
      _items[c]->store(datafile);
    } while (c++ < MAX_NO_RECS);
    datafile.close();
  }


 // Opens the file for reading, if it does not exist, it will create an
 // empty file and exits otherwise :
 // Loads Records from the file overwriting the old ones pointed by item.
 // This function makes sure when loading records into _item pointers, they
 // are deallocated before if they are already pointing to an item
 // closes the file

  void AidApp::loadRecs() {
    int readIndex = 0;
    char c;

    datafile.open(_filename, ios::in);

    if (datafile.fail()) {
      datafile.clear();
      datafile.close();
      datafile.open(_filename, ios::out);
    } else {
      while (datafile.fail() == false) {
        c = 0;
        if (_items[readIndex] != ((Item*)0)) {
          delete _items[readIndex];
          _items[readIndex] = 0;
        }
        if (datafile >> c && !datafile.fail()) {
          if (c=='P') {
            _items[readIndex] = new NFI();
          } else if (c=='N') {
            _items[readIndex] = new Perishable();
          }
        }
        if (_items[readIndex] != ((Item*)0)) {
          datafile >> c; // skip comma
          _items[readIndex++]->load(datafile);
        }
      }
    }

    _noOfItems = readIndex;
    datafile.close();
  }

  // Searchers for the item in the _items array with the same UPC.
  // if found, it will display the item in non-linear format and then
  // asks for the value of the items purchased, and if the value does not exceed
  // the number needed to fulfill the requirement, it will update the quantity onhand
  // value of the found record and then saves all the records to the file, overwriting
  // the old values
  void AidApp::updateQty(const char* UPC) {
    int c=SearchItems(UPC);
    int q, r = 0;
    if (c == -1) {
      cout << "Not found!" << endl;
    } else {
      _items[c]->display(cout, false);
      cout << endl << "Please enter the number of purchased items: ";
      cin >> q;
      if (cin.fail()) {
        cout << "Invalid Quantity value!" << endl;
      } else {
        r = _items[c]->qtyNeeded() - _items[c]->quantity();
        if (q <= r) {
          _items[c] += q;
        } else {
          _items[c] += r;
          cout << "Too much items, only " << r << " is needed, please return the extra " << (q+r) << " items." << endl;
        }
        saveRecs();
        cout << "Updated!" << endl;
      }
    }
  }


  // searches for an item in the _items array for the same upc
  // if found it will return the index of the found item in _items
  // otherwise returns -1
  int AidApp::SearchItems(const char* upc) const {
    int c = 0;
    while (((*_items[c])==upc)==false && c++ < _noOfItems);
    return c == _noOfItems ? -1 : c;
  }


  // creates a new item (NFI or Perishable) based on the argument
  // recieved dynamically, asks the user to fill in the values
  // if the user fills the values with no mistake, it will open the file
  // for writing, and then stores the item in the file.
  // and print a proper message.
  // if the user makes a mistake (cin fails) it will only display the item
  // to show the error.
  // in any way it will delete the item before exiting the function
  void AidApp::addItem(bool isPerishable) {
    Item* i;
    if (isPerishable) i = new Perishable();
    else              i = new NFI();

    cin >> *i;
    if (cin.fail()) {
      i->display(cout, false);
    } else {
      datafile.open(_filename, ios::out);
  		i->store(datafile);
      datafile.close();
  		cout << "Item added" << endl;
    }
  }

  // diplays the menu and receives the user selection
  // if valid, it will preform the action requsted:
  // 1, lists the items in the file on the screen
  // 2 and 3, adds the item and then re-loads the records
  //     from the file into the AidApp
  // 4, gets a UPC and then updates the quantity of it
  // 0, exits the program.
  int AidApp::run() {
    int n = 0;
    char u[MAX_UPC_LEN];

    while ((n=menu()) != 0) {
      if (n==1) {
        listItems();
      } else if (n==2) {
        addItem(false);
        loadRecs();
      } else if (n==3) {
        addItem(true);
        loadRecs();
      } else if (n==4) {
				cout << "Please enter the UPC: ";
				cin >> u;
				updateQty(u);
      } else {
        cout << "==Invalid Selection, try again.===";
  			cout << endl;
      }
    }

    cout << "Goodbye!!" << endl;
    return 0;
  }
}
