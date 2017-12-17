#include <iostream>

using namespace std;

class CaptureClass{
private:
  int one{1};
  int two{2};
public:
  void run(){
    int three = 3;
    int four = 4;
    auto lExpression = [&, this](){
      one = 111;
      cout << one << endl;
      cout << two << endl;
      cout << three << endl;
      cout << four << endl;
    };
    lExpression();
  }
};

// Test function to see conversion from lambda function to function pointers
void testDivide(int (*divide)(int a, int b), int a, int b){
  cout << divide(a,b) << endl;
}

int main() {

  // Define a simple lambda function
  auto simpleFunc = [](){cout << "Hello Lambda Func" << endl;};
  simpleFunc();

  // Define lambda functions with arguments and return type
  auto divideFunc = [](int a, int b) -> int{
    if(b == 0)
    {
      return 0;
    }
    return a/b;
  };

  // Convert divide function to function pointer
  testDivide(divideFunc, 9, 3);
  cout << divideFunc(9,3) << endl;

  // Capture expressions
  int one = 1;
  int two = 2;
  int three = 3;

  // Capture one and two by value
  [one, two](){ cout << one << ", " << two << endl; }();

  // Capture all variables by value
  [=](){ cout << one << ", " << two << endl; }();

  // Capture all variables by value and three by reference
  [=, &three](){ three = 7; cout << one << ", " << two << ", " << three << endl; }();
  cout << three << endl;

  // Capture all variables by reference
  [&](){ two = 8; cout << one << ", " << two << endl; }();
  cout << two << endl;

  // Capture this within class
  CaptureClass c;
  c.run();
}
