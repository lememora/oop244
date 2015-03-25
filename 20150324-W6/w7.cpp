// OOP244 Workshop 7
// File	w7.cpp
// Version 1.0
// Date	16/3/215
// Author	Fardad Soleimanloo
//
// Revision History
///////////////////////////////////////////////////////////
// Name			        Date		   Reason
// F.Soleimanloo	 16/3/2015	 Preliminary release
///////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
#include "Transcript.h"
using namespace oop244;

int main(){
  Transcript T("John Doe", 123456);
  cin >> T;
  cout << "-----------------------------" << endl;
  cout << T <<endl;
  return 0;
}