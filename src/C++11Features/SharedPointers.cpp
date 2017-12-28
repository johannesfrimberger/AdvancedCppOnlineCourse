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

int main() {

  shared_ptr<Test> test2(nullptr);

  {
    //shared_ptr<Test> test1(new Test());
    shared_ptr<Test> test1 = make_shared<Test>();

    // Test1 object is destroyed after the scope is left
    test2 = test1;
  }

  cout << "Finished" << endl;
  return 0;
}
