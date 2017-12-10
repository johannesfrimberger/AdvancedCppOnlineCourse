#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream inFile;
  string fileName = "text.txt";

  inFile.open(fileName, fstream::in);

  if(inFile.is_open()){

        while(inFile)
        {
          string line;

          // Read file until deliminator ':'
          getline(inFile, line, ':');

          // Read integer directly
          int population;
          inFile >> population;

          // Check for a line break
          inFile >> ws;

          // Check if end of file has been reached
          if(!inFile)
          {
            break;
          }

          // Print results
          cout << "'" << line << "' - '" << population << "'" << endl;
        }

        inFile.close();
  }
  else{
    cout << "File " << fileName << " could not be opened" << endl;
  }
}
