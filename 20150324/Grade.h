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
  };
}

#endif
