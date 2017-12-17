#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class RingBuffer{
  T* data;
  int pos;
  const int max_elements;
public:

  class iterator;

public:
  RingBuffer(const int max_elements):
    max_elements(max_elements),
    pos(0){
      data = new T[max_elements]();
    }

  ~RingBuffer(){
    delete[] data;
  }

  // Get pointer to data element
  const T* getData(const int pos) const {
    if(pos > max_elements){
      return NULL;
    }
    return (data+pos);
  }

  // Get ring buffer element
  T operator[](int idx) const{
    return data[idx];
  }

  // Add element to ring buffer
  void addElement(const T input){
    data[pos++] = input;
    pos = pos%max_elements;
  }

  // Return iterator pointing at the first element
  iterator begin(){
    return iterator(0, *this);
  }

  // Return iterator pointing outside of array
  iterator end(){
    return iterator(max_elements, *this);
  }

  // Print all current buffer elements
  friend ostream& operator<<(ostream &out, RingBuffer &number){
    out << "Buffer Elements: (";
    for(int i = 0; i < (number.max_elements-1); i++){
      out << number.data[i] << ", " << flush;
    }
    out << number.data[number.max_elements-1] << ")" << flush;
    return out;
  }
};

template<typename T>
class RingBuffer<T>::iterator{
private:
  int m_pos;
  RingBuffer<T>& buffer;
public:
  iterator(const int pos, RingBuffer<T>& buffer):
    m_pos(pos),
    buffer(buffer){

  }

  iterator operator++(){
    m_pos++;
    return *this;
  }

  T& operator*() const {
    return buffer[m_pos];
  }

  bool operator!=(const iterator &other) const{
    return m_pos != other.m_pos;
  }
};

int main() {

  // Instantiate RingBuffer element
  RingBuffer<double> buffer(3);

  // Print initial values
  cout << buffer << endl;

  // Add elements
  buffer.addElement(1);
  buffer.addElement(2);
  buffer.addElement(3);
  buffer.addElement(4);

  // Print all values after adding
  cout << buffer << endl;

  // Old C++98 iteration
  /*for(RingBuffer<double>::iterator it = buffer.begin(); it != buffer.end(); it++){
    cout << *it << endl;
  }*/

  // C++11 iteration
  for(auto el : buffer){
    cout << el << endl;
  }

}
