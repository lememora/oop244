#include <iostream>
using namespace std;
#include "Grade.h"
using namespace oop244;

void prnGrade(const Grade& G) {
  cout << G.name() << ", grade: " << G.value() << endl;
}

int main() {
  Grade G;
  int i, j, k = 0;

  if (G.value() == 'X') {
    cout << "G is in Safe empty state" << endl;
  }
  else {
    cout << "default constructor is not set properly" << endl;
  }
  if (!G.name()) {
    cout << "G is in Safe empty state" << endl;
  }
  else {
    cout << "default constructor is not set properly" << endl;
  }

  prnGrade(Grade("OOP344", 75));
  G = Grade("OOP244", 85);
  prnGrade(G);
  Grade GC = G;
  prnGrade(GC);

  for (j = 0; j < 100000; j++) {
    for (i = 45; i < 100; i += 10, k++) {
      GC = Grade("This is a test for memory reallocation with a long name", i);
      if (j == 99999) prnGrade(GC);
    }
  }

  cout << "Tested memory reallocation " << k << " times" << endl;
  return 0;
}
