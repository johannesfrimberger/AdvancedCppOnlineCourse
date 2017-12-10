#include <iostream>
#include <fstream>
using namespace std;

// Ensure that padding is 1
#pragma pack(push, 1)

struct Person{
  char name[50];
  int age;
  double height;
};

#pragma pack(pop)

int main() {

  // Create a binary file
  fstream outFile;
  string fileName = "test.bin";
  outFile.open(fileName, ios::binary | ios::out);

  if(outFile.is_open()){
        // Write a person struct to the binary file
        Person Frodo = {"Frodo", 200, 0.80};
        outFile.write(reinterpret_cast<char *>(&Frodo), sizeof(Person));
        Person Bilbo = {"Bilbo", 300, 0.75};
        outFile.write(reinterpret_cast<char *>(&Bilbo), sizeof(Person));
        outFile.close();
  }
  else{
    cout << "File " << fileName << " could not be opened" << endl;
  }

  // Read a binary file
  fstream inFile;
  inFile.open(fileName, ios::binary | fstream::in);

  if(inFile.is_open()){

    // Extract persons from it
    while(inFile)
    {
        // Read into person struct
        Person someone;
        inFile.read(reinterpret_cast<char *>(&someone), sizeof(Person));

        // Make sure that you don't print the last element twice
        if(!inFile){
            break;
        }

        cout << someone.name << " - " << someone.age << " - " << someone.height << endl;
    }
    inFile.close();
  }
  else{
    cout << "File " << fileName << " could not be opened" << endl;
  }

}
