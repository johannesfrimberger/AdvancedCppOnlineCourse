#include <iostream>
using namespace std;

void mightGoWrong(){
  bool error1 = false;
  bool error2 = true;

  // Throw integer error code
  if(error1){
    throw 8;
  }

  // Throw error message
  if(error2){
    throw "Error detected";
  }
}

// Allocate a huge memory section that will cause a bad_alloc
class MemoryAllocation{
public:
  MemoryAllocation(){
    char *memory = new char[9999999999999999];
    delete[] memory;
  }
};

// Define my own exception class
class MyException : public exception
{
public:
  MyException(const int exception_type):
    _exception_type(exception_type){

  }

  virtual const char* what() const throw(){
    switch (_exception_type) {
      case 0:
        return "Regular Exception";
      default:
        return "Special Exception";
    }

  }
private:
  const int _exception_type;
};

// Throw MyException within a function
void throwMyException(const int param)
{
  bool error = true;
  if(error){
    throw MyException(param);
  }
}

int main() {

  // Check mightGoWrong method
  try{
    mightGoWrong();
  }
  catch(int &e){
    cout << "Expection with ErrorCode: " << e << endl;
  }
  catch(char const* e){
    cout << "Expection with message: " << e << endl;
  }

  // Check memory allocation
  try{
    MemoryAllocation memory;
  }
  catch(bad_alloc &e){
    std::cout << "Bad allocation with error: " << e.what() << endl;
  }

  // Check MyException class with two different parameters
  for(int i = 0; i < 2; i++)
  {
    try{
      throwMyException(i);
    }
    catch(MyException &e)
    {
      cout << "Expection with message: " << e.what() << endl;
    }
  }

  // Debug print to show that program is still running
  cout << "Still running" << endl;

  return 0;
}
