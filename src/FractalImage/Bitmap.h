#ifndef _BIT_MAP_HEADER_H_
#define _BIT_MAP_HEADER_H_

#include "BitMapFileHeader.h"
#include "BitMapInfoHeader.h"
#include <string>
#include <fstream>

using namespace std;

class Bitmap{
private:
  const int _width;
  const int _height;
  unique_ptr<uint8_t[]> _pPixels{nullptr};

public:
  explicit Bitmap(const int width, const int height):
    _width(width),
    _height(height),
    _pPixels(new uint8_t[width*height*3]{})
    {
    }

  bool write(string filename){

    //
    BitmapFileHeader fileHeader;
    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) +
      (_width * _height * 3);
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    //
    BitmapInfoHeader infoHeader;
    infoHeader.width = _width;
    infoHeader.height = _height;

    // Open file for writing
    fstream outFile;
    outFile.open(filename, ios::binary | ios::out);

    // Check that file can be opened
    if(!outFile){
      cout << "File " << filename << " could not be opened" << endl;
      return false;
    }

    // Write data
    outFile.write(reinterpret_cast<char *>(&fileHeader), sizeof(fileHeader));
    outFile.write(reinterpret_cast<char *>(&infoHeader), sizeof(infoHeader));
    outFile.write(reinterpret_cast<char *>(_pPixels.get()), _width * _height * 3);

    // Close file after writing to it
    outFile.close();

    // Check that file can be closed
    if(!outFile){
      cout << "File " << filename << " could not be closed" << endl;
      return false;
    }

    // Everything OK
    return true;
  }

  void setPixel(const int x, const int y, const uint8_t red, const uint8_t green, const uint8_t blue){
    uint8_t *pPixel = _pPixels.get();

    pPixel += (y*3) * _width + (x * 3);

    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
  }

  virtual ~Bitmap(){

  }

};

#endif //_BIT_MAP_HEADER_H_
