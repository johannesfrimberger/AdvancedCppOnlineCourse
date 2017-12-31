#ifndef _RGB_H_
#define _RGB_H_

struct RGB{
  double r{0};
  double g{0};
  double b{0};

  explicit RGB(double r, double g, double b) :
    r(r),
    g(g),
    b(b)
    {}
};

RGB operator-(const RGB& first, const RGB& second){
  return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
}

#endif //_ZOOM_H_
