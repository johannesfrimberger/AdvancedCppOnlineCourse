#include <iostream>

using namespace std;

class Complex{
  double real;
  double imaginary;
public:
  Complex(): real(0), imaginary(0){
  }

  Complex(const double real, const double imaginary):
    real(real), imaginary(imaginary){
  }

  Complex(const Complex &other):
    real(other.real), imaginary(other.imaginary){
  }

  double getReal() const {
    return real;
  }

  double getImaginary() const {
    return imaginary;
  }

  const Complex& operator=(const Complex& other){
    real = other.real;
    imaginary = other.imaginary;
    return *this;
  }

  Complex operator*() const{
    return Complex(real, -imaginary);
  }

  Complex operator+(const Complex& other) const{
    return Complex(real + other.real, imaginary + other.imaginary);
  }
};

ostream& operator<<(ostream &out, Complex &number){
  out << "(" << number.getReal() << ", " << number.getImaginary() << ")" << flush;
  return out;
}

int main() {

  Complex a(2, 3);
  Complex b(5, 7);
  Complex c = a+b;

  cout << a << endl;

  return 0;
}
