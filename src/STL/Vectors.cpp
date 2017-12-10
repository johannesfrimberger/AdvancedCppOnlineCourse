#include "Candidate.h"
#include <vector>

using namespace std;

int main() {

  // Initialize vector with random elements
  std::vector<Candidate> vec;
  vec.push_back(Candidate("Mike", 10));
  vec.push_back(Candidate("Ike", 4));
  vec.push_back(Candidate("Aike", 5));
  vec.push_back(Candidate("Tike", 1));
  vec.push_back(Candidate("Yike", 532));

  // Sort elements using Candidates < operator referencing name
  sort(vec.begin(), vec.end());
  for(vector<Candidate>::iterator it = vec.begin(); it != vec.end(); it++ ){
      it->print();
      cout << endl;
  }

  cout << endl;

  // Sort elements using comp operator referencing id
  sort(vec.begin(), vec.end(), comp);
  for(vector<Candidate>::iterator it = vec.begin(); it != vec.end(); it++ ){
      it->print();
      cout << endl;
  }

  return 0;
}
