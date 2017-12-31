#include <iostream>
#include "FractalCreator.h"

using namespace std;

int main() {

  int const WIDTH = 800;
  int const HEIGHT = 600;
  FractalCreator img(WIDTH, HEIGHT);

  img.addRange(0.0, RGB(0, 0, 255));
	img.addRange(0.05, RGB(255, 99, 71));
	img.addRange(0.08, RGB(255, 215, 0));
	img.addRange(1.0, RGB(255, 255, 255));

	img.addZoom(Zoom(295, 202, 0.1));
	img.addZoom(Zoom(312, 304, 0.1));

  img.run("test.bmp");

  cout << "Finished." << endl;
  return 0;
}
