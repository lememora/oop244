// OOP244 Workshop 6: Operators
// File Grade.h
// Version 1.0
// Date 2015/03/25
// Author   Rafael Moraes
// Description
// Header for Grade class
//
// Revision History
// -----------------------------------------------------------
// Name         Date        Reason
// R.Moraes     2015/03/25  Assignment completion
////////////////////////////////////////////////////////////////

#ifndef __GRADE_H__
#define __GRADE_H__
#include <iostream>

namespace oop244 {
  class Grade {
  private:
    char* _name;
    int _mark;
  public:
    Grade();
    Grade(const char *name, int mark);
    Grade(const Grade &grade);
    ~Grade();
    Grade& operator=(const Grade& grade);
    const char* name() const;
    char value() const;
    Grade& operator++();
    Grade& operator--();
    Grade operator++(int);
    Grade operator--(int);
    bool operator<(const Grade& RO);
    bool operator>(const Grade& RO);
    bool operator<=(const Grade& RO);
    bool operator>=(const Grade& RO);
    bool operator==(const Grade& RO);
    bool operator!=(const Grade& RO);
    Grade& operator/=(int n);
    Grade& operator+=(const Grade& RO);
    friend Grade operator+(const Grade& LO, const Grade& RO);
    friend std::ostream& operator<<(std::ostream& os, const Grade& RO);
    std::istream& operator>>(std::istream& is, Grade& RO);
  };
}

#endif
