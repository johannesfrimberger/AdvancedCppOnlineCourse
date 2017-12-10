#include "Candidate.h"
#include <map>

using namespace std;

int main() {

  //
  map<Candidate, int> peoples;
  peoples[Candidate("Mike", 100)] = 123;
  peoples[Candidate("Mike", 200)] = 500;
  peoples[Candidate("Dike", 100)] = 123;
  peoples[Candidate("Tike", 100)] = 123;

  for(map<Candidate, int>::iterator it = peoples.begin(); it != peoples.end(); it++){
    it->first.print();
    cout << " - " << it->second << endl;
  }

  cout << endl;

  // Implement a multimap container
  multimap<int, string> lookup;

  lookup.insert(make_pair(10, "Mike"));
  lookup.insert(make_pair(10, "Tike"));
  lookup.insert(make_pair(10, "Dike"));
  lookup.insert(make_pair(20, "Mike"));

  // Print all elements
  for(multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++ ){
    cout << it->first << " - " << it->second << endl;
  }

  cout << endl;

  // Find all elements with key 10
  pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(10);

  for(multimap<int, string>::iterator it = its.first; it != its.second; it++){
    cout << it->first << " - " << it->second << endl;
  }

  return 0;
}
