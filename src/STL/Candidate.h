#ifndef _CANDIDATE_H
#define _CANDIDATE_H

#include <iostream>

using namespace std;

class Candidate{
  string name;
  int id;
public:
  Candidate(): name(""), id(0){

  }

  Candidate(const string name, const int id): name(name), id(id){

  }

  void print() const{
    cout << id << " - " << name << flush;
  }

  bool operator<(const Candidate& other) const{
    return name > other.name;
  }

  friend bool comp(Candidate& a, Candidate& b);
};

bool comp(Candidate& a, Candidate& b){
  return a.id < b.id;
}

#endif
