#include <new>
#include <cstring>
using namespace std;
#include "Grade.h"

namespace oop244 {

  Grade::Grade() {
    _name = nullptr;
    _mark = -1;
  }

  Grade::Grade(const char* name, int mark) : Grade() {
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
      _name = nullptr;
    }
  }

  /* Assignment operator */
  Grade& Grade::operator=(const Grade& grade) {
    if (this != &grade) {
      if (_name) {
        delete [] _name;
        _name = nullptr;
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

}
