#include <iostream>

using namespace std;

class Test{

};

template<typename T>
void call(T &&arg){
  check(arg);
}

template<typename T>
void perfectCall(T &&arg){
  //check(static_cast<T>(arg)); // equivalent
  check(forward<T>(arg));
}

void check(Test& test){
  cout << "lvalue" << endl;
}

void check(Test&& test){
  cout << "rvalue" << endl;
}

int main() {

  Test test;

  // Collapses to an lvalue Reference
  auto &&t = test;
  check(t);

  // No perfect forwarding, lvalue is passed
  call(Test());

  // Pass rvalue
  perfectCall(Test());

  return 0;
}
