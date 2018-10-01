#include <iostream>

struct Base {
    virtual void reimplementMe(int) {}
};

struct Derived : public Base  {
    virtual void reimplementMe(int) {}
};

int main() {
  return 0;
}
