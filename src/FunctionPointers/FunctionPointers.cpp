#include <iostream>
#include <vector>

using namespace std;

void printNumberAndText(string s, int n){
  cout << s << " with number " << n << endl;
}

bool match(int n){
  return n < 10;
}

bool matchBigger(int n){
  return n >= 10;
}

int myCount(vector<int> numbers, bool (*m)(int)){
  int count = 0;
  for(auto n : numbers){
    count += m(n) ? 1 : 0;
  }
  return count;
}

int main() {

  void (*pTest)(string, int) = printNumberAndText;
  pTest(string("Abc"), 10);

  vector<int> numbers {1, 10, 12, 4, 123, 6, 8, 1, 12};
  cout << "Vector has " << numbers.size() << " elements" << endl;

  cout << "With " << count_if(numbers.begin(), numbers.end(), match) << " Elements <10" << endl;
  cout << "With " << myCount(numbers, match) << " Elements <10" << endl;
  cout << "With " << myCount(numbers, matchBigger) << " Elements >=10" << endl;

  return 0;
}
