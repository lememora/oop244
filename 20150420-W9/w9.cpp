#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "add.h"
using namespace oop244;


class Account{
  char _name[81];
  double _balance;
public:
  Account(const char* name = "Saving", double balance = 0.0){
    strcpy(_name, name);
    _balance = balance;
  }
  Account& operator+=(const Account& A){
    _balance += A._balance;
    return *this;
  }
  ostream& display(ostream& os)const{
    return os << _name << " account balance: $" << fixed << setprecision(2) << _balance;
  }
};

ostream& operator<<(ostream& os, const Account& A){
  return A.display(os);
}

int main(){
  int
    i = 10,
    j = 20;
  double
    x = 1.2,
    y = 2.3;
  Account
    A("Checking", 1000),
    B("Saving", 2000);
  char
    name[80] = "Homer";

  addTo(&i, &j);
  addTo(&x, &y);
  addTo(&A, &B);
  addTo(name, " Jay");
  addTo(name, " Simpson");
  cout << i << endl;
  cout << x << endl;
  cout << A << endl;
  cout << name << endl;
  return 0;
}