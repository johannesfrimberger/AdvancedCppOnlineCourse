#include <iostream>
#include <fstream>
using namespace std;

int main() {

  fstream outFile;
  string fileName = "text.txt";

  // Open text file in write mode
  outFile.open(fileName, fstream::out);

  if(outFile.is_open()){
        // Write something to file (will be read by ReadFiles later)
        outFile << "Population Germany: " << 82457000 << endl;
        outFile << "Population France: " << 66991000 << endl;
        outFile << "Population Spain: " << 46438422 << endl;
        outFile.close();
  }
  else{
    cout << "File " << fileName << " could not be opened" << endl;
  }
}
