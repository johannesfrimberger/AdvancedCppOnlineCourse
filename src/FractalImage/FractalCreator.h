#ifndef FRACTAL_CREATOR_H_
#define FRACTAL_CREATOR_H_

#include <string>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"
using namespace std;

class FractalCreator {
private:

  int _width;
  int _height;
  int _total;

  ZoomList _zoomList;
  Bitmap _bitmap;

  unique_ptr<int[]> _histogram;
  unique_ptr<int[]> _fractal;

  vector<double> _ranges;
  vector<RGB> _colors;
  vector<int> _rangeTotals;

  bool _gotFirstRange{false};

public:
	FractalCreator(const int width, const int height):
    _width(width), _height(height), _total(0),
    _zoomList(width, height),
    _bitmap(width, height),
    _histogram(new int[Mandelbrot::MAX_ITERATIONS] { 0 }),
    _fractal(new int[width * height] { 0 })
  {
    addZoom(Zoom(width / 2, height / 2, 4.0 / width));
  }

	virtual ~FractalCreator(){

  }

  void run(string name){
    calculateIteration();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();
    writeBitmap(name);
  }

  void addZoom(const Zoom& zoom){
    _zoomList.add(zoom);
  }

  void addRange(const double rangeEnd, const RGB& rgb){
    _ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    _colors.push_back(rgb);

    if(_gotFirstRange){
      _rangeTotals.push_back(0);
    }
    _gotFirstRange = true;
  }

private:

	void calculateIteration(){
    int* fractalPtr = _fractal.get();
    for (int y = 0; y < _height; y++) {
      for (int x = 0; x < _width; x++) {
        pair<double, double> coords = _zoomList.doZoom(x, y);

        int iterations = Mandelbrot::getIterations(coords.first, coords.second);

        *fractalPtr = iterations;
        fractalPtr++;
        if (iterations != Mandelbrot::MAX_ITERATIONS) {
          _histogram[iterations]++;
        }
      }
    }
  }

  void calculateTotalIterations(){
    _total = 0;
    int* histPtr = _histogram.get();
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
      _total += *histPtr++;
    }
  }

  void calculateRangeTotals(){
    int rangeIndex = 0;

  	for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++) {
  		int pixels = _histogram[i];

  		if(i >= _ranges[rangeIndex+1]) {
  			rangeIndex++;
  		}

  		_rangeTotals[rangeIndex] += pixels;
  	}
  }

	void drawFractal(){

    int* fractalPtr = _fractal.get();
    for (int y = 0; y < _height; y++) {
      for (int x = 0; x < _width; x++) {

        uint8_t red = 0;
        uint8_t green = 0;
        uint8_t blue = 0;

        int iterations = *fractalPtr++;

        int range = getRange(iterations);
        int rangeTotal = _rangeTotals[iterations];

        const RGB& startColor = _colors[range];
        const RGB& endColor = _colors[range+1];
        RGB colorDiff = endColor - startColor;

        if (iterations != Mandelbrot::MAX_ITERATIONS) {

          double totalPixels = 0;

          int* histPtr = _histogram.get();
          for (int i = 0; i <= iterations; i++) {
            totalPixels += *histPtr++;
          }

          const double hue = (totalPixels/(double)rangeTotal);
          red = startColor.r + colorDiff.r * hue;
          green = startColor.g + colorDiff.g * hue;
          blue = startColor.b + colorDiff.b * hue;
        }
        _bitmap.setPixel(x, y, red, green, blue);
      }
    }
  }

  int getRange(const int iterations) const{
    int range = 0;
    for(int i = 1; i < _ranges.size(); i++){
      range = i;
      if(_ranges[i] > iterations){
        break;
      }
    }

    range--;

    return range;
  }

	void writeBitmap(string name){
    _bitmap.write(name);
  }

};

#endif // FRACTAL_CREATOR_H_
