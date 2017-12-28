#include <iostream>

using namespace std;

class Parent{
  virtual void speak(){
    cout << "Parent" << endl;
  }
};

class Brother : public Parent{

};

class Sister : public Parent{

};

int main() {

  Parent parent;
  Brother brother;
  Sister sister;

  // Static Casts
  {
    // Unsafe
    Brother *pb = static_cast<Brother*>(&parent);

    // Also unsafe --> Checks only at compile time
    Parent *ppb = &brother;
    Brother *pbb = static_cast<Brother*>(ppb);

    // R-Value Reference
    Parent &&p = static_cast<Parent&&>(parent);
  }

  // Dynamic Cast
  {
      Parent *ppb = &parent;
      Brother *pbb = dynamic_cast<Brother*>(ppb);

      if(pbb != nullptr){
          cout << pbb << endl;
      }
      else {
        cout << "Invalid Cast!" << endl;
      }
  }

  // Reinterpret Cast
  {
    // Unsafe
    Parent *ppb = &parent;
    Sister *pbb = reinterpret_cast<Sister*>(ppb);

    if(pbb != nullptr){
        cout << pbb << endl;
    }
    else {
      cout << "Invalid Cast!" << endl;
    }
  }

  return 0;
}
