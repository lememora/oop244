#include <iostream>

#ifndef __244_DATE_H__
#define __244_DATE_H__
// header file includes

#define NO_ERROR   0 // No error the date is valid
#define CIN_FAILED 1 // istream failed when entering information
#define YEAR_ERROR 2 // Year value is invalid
#define MON_ERROR  3 // Month value is invalid
#define DAY_ERROR  4 // Day value is invalid

namespace oop244{
// Error code values gos here

  class Date{
  private:
    // private member variables
    // Holds the year; a four digit integer between MIN_YEAR and MAX_YEAR
    int _year;
    // Month of the year, between 1 to 12
    int _mon;
    // Day of the month
    int _day;
    // This variable is going to hold an error code with which the caller program can find out if the date value is valid or not. And also can find out which part is erroneous.
    int _readErrorCode;

    // privaet memeber functions and setters
    int value()const;

    // Sets the _readErrorCode member-variable to one of the valid values.
    void errCode(int errorCode);

    // validate date to be in range in the order of year, mon and then day
    void validate();

  public:
    // constructor
    Date();
    Date(int year, int month, int day);


    // operator overloads
    // These operators return the comparison result of the return value of the value() function in Left and right operands (The Date objects at left and right side of the operators).
    // For example '''operator<''' return true if this->value() is less than D.value() or else it returns false.
    bool operator==(const Date& D) const;
    bool operator!=(const Date& D) const;
    bool operator<(const Date& D) const;
    bool operator>(const Date& D) const;
    bool operator<=(const Date& D) const;
    bool operator>=(const Date& D) const;

    // IO member funcions
    // Reads the date in following format: YYYY/MM/DD (i.e 2015/03/24) from the console.
    std::istream& read(std::istream& istr);

    // Writes the date using the ostr argument in the following format and returns the ostr: YYYY/MM/DD
    // error: non-member function cannot have 'const' qualifier
    std::ostream& write(std::ostream& ostr) const;

    // public member fucntions and getters
    int mdays() const;
    int errCode() const;
    bool bad() const;

  };
  // operator << and >> overloads prototypes for ostream and istream go here
  std::ostream& operator<<(std::ostream& os, const Date& D);
  std::istream& operator>>(std::istream& is, Date& D);



}
#endif
