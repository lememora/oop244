// OOP244 Workshop 6: Operators
// File	w6.cpp
// Version 1.0
// Date	16/3/215
// Author	Fardad Soleimanloo
// Description
// This file is used to test the implemetation of 
// operators for Grade class
//
// Revision History
///////////////////////////////////////////////////////////
// Name			        Date		   Reason
// F.Soleimanloo	 16/3/2015	 Preliminary release
///////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
#include "Grade.h"
using namespace oop244;
void LogicalOperatorTests(const Grade& X, const Grade& Y);
void UnaryPrefixTest();
void UnaryPostfixTest();
void BinaryWithSideEffectTest();

int main(){
  Grade X, Y, Z;
  cout << "Enter value for X: (Name: \"EAC150\", Mark: 75)"<<endl;
  cin >> X;
  cout << "Enter value for Y: (Name: \"PSY100\", 65)" << endl;
  cin >> Y;
  LogicalOperatorTests(X, Y);
  UnaryPrefixTest();
  UnaryPostfixTest();
  BinaryWithSideEffectTest();
  return 0;
}

void LogicalOperatorTests(const Grade& X, const Grade& Y){
  cout << "--------------Logical operator test" << endl;
  Grade
    Z = Y;
  cout 
    << "X: " << X << endl
    << "Y: " << Y << endl
    << "Z: " << Z << endl;
  if (X > Y){
    cout << X << " Has higher mark than " << Y << endl;
  }
  else{
    cout << "bad operator>()" << endl;
  }
  if (Y < X){
    cout << Y << " Has lower mark than " << X << endl;
  }
  else{
    cout << "bad operator<()" << endl;
  }
  if (X >= Y){
    cout << X << " is higher or equal to " << Y << endl;
  }
  else{
    cout << "bad operator>=()" << endl;
  }
  if (Y <= X){
    cout << Y << " is lower or equal to " << X << endl;
  }
  else{
    cout << "bad operator<=()" << endl;
  }
  if (Z >= Y){
    cout << Z << " is higher or equal to " << Y << endl;
  }
  else{
    cout << "bad operator>=()" << endl;
  }
  if (Y <= Z){
    cout << Y << " is lower or equal to " << Z << endl;
  }
  else{
    cout << "bad operator<=()" << endl;
  }
  if (Y == Z){
    cout << Y << " is equal to " << Z << endl;
  }
  else{
    cout << "bad operator==()" << endl;
  }
  if (Y != X){
    cout << Y << " is not equal to " << X << endl;
  }
  else{
    cout << "bad operator==()" << endl;
  }
  cout << "--------------End of logical operator test" << endl;
}

void UnaryPrefixTest(){
  Grade X("OOP244", 70);
  Grade Z;
  cout << "--------------------prefix ++ and -- test" << endl;
  cout << "Before Z = ++X: " << endl << "Z: " << Z << endl << "X: " << X << endl;
  Z = ++X;
  cout << "After  Z = ++X: " << endl << "Z: " << Z << endl << "X: " << X << endl;
  cout << "-----------";
  X = Grade("OOP244", 70);
  Z = Grade();
  cout << "Before Z = --X: " << endl << "Z: " << Z << endl << "X: " << X << endl;
  Z = --X;
  cout << "After  Z = --X: " << endl << "Z: " << Z << endl << "X: " << X << endl;
}

void UnaryPostfixTest(){
  Grade Y("OOP344", 70);
  Grade Z;
  cout << "--------------------postfix ++ and -- test" << endl;
  cout << "Before Z = Y++: " << endl << "Z: " << Z << endl << "Y: " << Y << endl;
  Z = Y++;
  cout << "After  Z = Y++: " << endl << "Z: " << Z << endl << "Y: " << Y << endl;
  cout << "----------" << endl;
  Y = Grade("OOP344", 70);
  Z = Grade();
  cout << "Before Z = Y--: " << endl << "Z: " << Z << endl << "Y: " << Y << endl;
  Z = Y--;
  cout << "After  Z = Y--: " << endl << "Z: " << Z << endl << "Y: " << Y << endl;
}

void BinaryWithSideEffectTest(){

  Grade X("OOP244", 70);
  Grade Y("OOP344", 70);
  Grade Z;

  cout << "----------------------Testing += and /=" << endl;
  Y += Z;  
  cout << "---Y should remain 70:" << endl;
  cout << "Y: " << Y << endl;
  Z += Y;   
  cout << "---Z should remain unset: " << endl;
  cout << "Z: " << Z << endl;
  Z = Grade("OOP244", 10);
  Y += Z;
  cout << "---Y should be 80: " << endl;
  cout << "Y: " << Y << endl;
  Y += X;
  cout << "---Y should be 150: " << endl;
  cout << "Y: " << Y << endl;
  Y /= 2;
  cout << "---Y should be 75: " << endl;
  cout << "Y: " << Y << endl;
}
