#include <iostream>

using namespace std;

struct Test{
  virtual bool operator()(string &text)=0;
};

struct MatchTest: public Test{
  virtual bool operator()(string &text){
      return text == "lion";
  }
};

void check(string text, Test &test){
  cout << test(text) << endl;
}

int main() {

  MatchTest test;
  string text = "lion";
  check(text, test);

  return 0;
}
