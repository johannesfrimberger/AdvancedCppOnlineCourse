#ifndef _ZOOM_LIST_H_
#define _ZOOM_LIST_H_

#include "Zoom.h"
#include <vector>
#include <utility>

class ZoomList{
private:

  double _xCenter{.0};
  double _yCenter{.0};
  double _scale{1.};

  int _height{0};
  int _width{0};
  std::vector<Zoom> _zooms;

public:
  ZoomList(int width, int height):
    _height(height),
    _width(width)
    {}

  void add(const Zoom &zoom){
    _zooms.push_back(zoom);

    _xCenter += (zoom.x - _width / 2) * _scale;
    _yCenter += (zoom.y - _height / 2) * _scale;

    _scale *= zoom.scale;

    cout << _xCenter << ", " << _yCenter << ", " << _scale << endl;
  }

  pair<double, double> doZoom(int x, int y){
    double xFractal = (x - _width / 2) * _scale + _xCenter;
  	double yFractal = (y - _height / 2) * _scale + _yCenter;

  	return pair<double, double>(xFractal, yFractal);
  }
};

#endif //_ZOOM_LIST_H_
