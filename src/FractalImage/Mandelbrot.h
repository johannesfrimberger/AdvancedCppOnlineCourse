#ifndef _MANDELBROT_HEADER_H_
#define _MANDELBROT_HEADER_H_

#include <complex>

using namespace std;

class Mandelbrot{
private:

public:
  static const int MAX_ITERATIONS=1000;

  Mandelbrot(){}

  virtual ~Mandelbrot(){}

  static int getIterations(double x, double y){

    complex<double> z = 0;
    complex<double> c(x, y);

    int iterations = 0;
    while (iterations < MAX_ITERATIONS) {
      z = z*z + c;

      if(abs(z) > 2){
        break;
      }
      iterations++;
    }

    return iterations;
  }
};

#endif // _MANDELBROT_HEADER_H_
