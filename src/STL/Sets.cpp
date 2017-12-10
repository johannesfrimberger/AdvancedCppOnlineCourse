#include "Candidate.h"
#include <set>

using namespace std;

int main() {

  // Add random numbers
  set<int> numbers;
  numbers.insert(10);
  numbers.insert(5);
  numbers.insert(120);
  numbers.insert(5);
  numbers.insert(30);
  numbers.insert(10);

  // Print items
  for(set<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
    std::cout << *it << endl;
  }

  return 0;
}
