#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

class Test{
public:
  int add(int a, int b, int c){
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
  }

  static int staticAdd(int a, int b, int c){
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
  }
};

int add(int a, int b, int c){
  cout << a << ", " << b << ", " << c << endl;
  return a + b + c;
}

void run(function<int(int, int)> f){
  f(0, 0);
}

int main() {

  {
    auto calculate = bind(add, _2, 1, _1);

    // Call bind method directly
    cout << calculate(1, 2) << endl;

    // Call bind method with run method
    run(calculate);
  }

  // Bound to a method
  {
    Test test;
    auto calculate = bind(&Test::add, Test(), _2, 2, _1);
    run(calculate);
  }

  // Bound to a static method
  {
    Test test;
    auto calculate = bind(&Test::staticAdd, _2, 3, _1);
    run(calculate);
  }

  return 0;
}
