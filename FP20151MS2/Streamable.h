#ifndef __244__Streamable__
#define __244__Streamable__
// hearfile includes:


namespace oop244{
  class Streamable{
  public:
    // pure virutal methods:

    // virtual void draw() const = 0;  // = 0 means it is "pure virtual"

    virtual std::fstream& Store(std::fstream& file) const = 0;
    virtual std::fstream& Load(std::fstream& file) const = 0;
    virtual std::ostream& display(std::ostream& os, bool linear) const = 0;
    virtual std::istream& conInput(std::istream& is) const = 0;

    // virutal destructor:

    virtual ~Streamable();

  };
  // Non-memenber operator overoad prototypes for cin and cout:

  std::ostream& operator<<(std::ostream& os, const Streamable& D);
  std::istream& operator>>(std::istream& is, Streamable& D);

}
#endif