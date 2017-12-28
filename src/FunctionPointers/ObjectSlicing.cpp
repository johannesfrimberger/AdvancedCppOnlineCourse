#include <iostream>

using namespace std;

class Parent{

  int one;

public:
  Parent(): one(1){

  }

  Parent(const Parent &other): one(1){
    one = other.one;
    cout << "Copy" << endl;
  }

  virtual void print(){
    cout << "Parent" << endl;
  }
};

class Child : public Parent{
  int two;
public:

  Child():two(2){

  }

  virtual void print(){
    cout << "Child" << endl;
  }
};

int main() {

  Child c1;
  Parent &p1 = c1;
  p1.print();

  // p2 is using copy constructor of Parent class
  // Private variable "one" is copied from Child but not initialized there
  // It is sliced off
  Parent p2 = Child();
  p2.print();

  return 0;
}
