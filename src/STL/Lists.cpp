#include <iostream>
#include <list>

using namespace std;

int main() {

  // Initialize list with random elements
  std::list<int> number;
  number.push_back(1);
  number.push_back(2);
  number.push_back(3);
  number.push_back(4);
  number.push_back(5);
  number.push_front(0);

  // Remove number 3 and add element in front of 2
  list<int>::iterator it = number.begin();
  while(it != number.end()){
    if(*it == 2){
      number.insert(it, 1234);
    }

    if(*it == 3){
      it = number.erase(it);
    }
    else{
      it++;
    }
  }

  // Print all list elements
  for(list<int>::iterator printIt = number.begin(); printIt != number.end(); printIt++ ){
      cout << *printIt << endl;
  }

  return 0;
}
