// OOP244 Workshop 6: Operators
// File Grade.cpp
// Version 1.0
// Date 2015/03/25
// Author   Rafael Moraes
// Description
// Grade class
//
// Revision History
// -----------------------------------------------------------
// Name         Date        Reason
// R.Moraes     2015/03/25  Assignment completion
////////////////////////////////////////////////////////////////

#include <new>
#include <cstring>
using namespace std;
#include "Grade.h"

namespace oop244 {

  Grade::Grade() {
    _name = (char*)0;
    _mark = -1;
  }

  Grade::Grade(const char* name, int mark) {
    if (name) {
      _name = new (nothrow) char[strlen(name)+1];
      strcpy(_name, name);
    }
    if (mark >= 0 && mark <= 100) {
      _mark = mark;
    }
  }

  /* Copy constructor */
  Grade::Grade(const Grade& grade) {
    if (grade._name) {
      _name = new (nothrow) char[strlen(grade._name)+1];
      strcpy(_name, grade._name);
    }
    _mark = grade._mark;
  }

  /* Destructor */
  Grade::~Grade() {
    if (_name) {
      delete [] _name;
      _name = (char*)0;
    }
  }

  /* Assignment operator */
  Grade& Grade::operator=(const Grade& grade) {
    if (this != &grade) {
      if (_name) {
        delete [] _name;
        _name = (char*)0;
      }
      if (grade._name) {
        _name = new (nothrow) char[strlen(grade._name)+1];
        strcpy(_name, grade._name);
      }
      _mark = grade._mark;
    }
    return *this;
  }

  const char* Grade::name() const {
    return _name;
  }

  char Grade::value() const {
    if      (_mark >= 0 && _mark < 50) return 'F';
    else if (_mark >=50 && _mark < 60) return 'D';
    else if (_mark >=60 && _mark < 70) return 'C';
    else if (_mark >=70 && _mark < 80) return 'B';
    else if (_mark >=80 && _mark < 90) return 'A';
    else if (_mark >=90 && _mark<=100) return '+';
    return 'X';
  }

  Grade& Grade::operator++() {
    if (_mark >= 0 and _mark < 100) {
      _mark++;
    }
    return *this;
  }

  Grade& Grade::operator--() {
    if (_mark >= 0) {
      _mark--;
    }
    return *this;
  }

  Grade Grade::operator++(int) {
    Grade tmp = *this;
    ++*this;
    return tmp;
  }

  Grade Grade::operator--(int) {
    Grade tmp = *this;
    --*this;
    return tmp;
  }

  bool Grade::operator<(const Grade& RO) const {
    return _mark < RO._mark;
  }

  bool Grade::operator>(const Grade& RO) const {
    return _mark > RO._mark;
  }

  bool Grade::operator<=(const Grade& RO) const {
    return _mark <= RO._mark;
  }

  bool Grade::operator>=(const Grade& RO) const {
    return _mark >= RO._mark;
  }

  bool Grade::operator==(const Grade& RO) const {
    return _mark == RO._mark;
  }

  bool Grade::operator!=(const Grade& RO) const {
    return _mark != RO._mark;
  }

  Grade& Grade::operator/=(int n) {
    if (n != 0) {
      _mark/=n;
    }
    return *this;
  }

  Grade& Grade::operator+=(const Grade& RO) {
    if (RO._mark >= 0) {
      _mark+= RO._mark;
    }
    return *this;
  }

  Grade operator+(const Grade& LO, const Grade& RO) {
    Grade tmp(LO._name, LO._mark + RO._mark);
    return tmp;
  }

  std::ostream& operator<<(std::ostream& os, const Grade& RO) {
    if (RO._mark < 0 || RO._name  == (char*)0) {
      os << "Unset Grade Object";
    } else {
      os << RO._name << ": " << RO._mark << "%, " << RO.value();
    }
    return os;
  }

  std::istream& operator>>(std::istream& is, Grade& RO) {
	
	if (RO._name) {
	  delete [] RO._name;
	  RO._name = (char*)0;
	}
	  
//	http://www.cplusplus.com/reference/istream/istream/getline/
	  
    char name[256];
    cout << "Subject name: ";
    is.getline(name, 256);
	RO._name = new (nothrow) char[strlen(name)+1];
	strcpy(RO._name, name);

    cout << "Mark: ";
    is >> RO._mark;
	is.ignore();

    return is;
  }
}
