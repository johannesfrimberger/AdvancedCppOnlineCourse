#include <iostream>
#include <memory>

using namespace std;

class Test{
public:
  Test(){
    cout << "Created" << endl;
  }

  ~Test(){
    cout << "Destroyed" << endl;
  }

  void greet(){
    cout << "Hello" << endl;
  }
};

class Temp{
  unique_ptr<Test> pTest;
public:
  Temp(): pTest(new Test){

  }
};

int main() {

  {
    unique_ptr<Test[]> pTest(new Test[3]);
    pTest[2].greet();
  }
  cout << "Finished" << endl;

  {
    Temp t;
  }
  cout << "Finished with UniquePointer member" << endl;

  return 0;
}
