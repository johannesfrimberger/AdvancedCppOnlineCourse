#ifndef _BIT_MAP_FILE_HEADER_H_
#define _BIT_MAP_FILE_HEADER_H_

#include <cstdint>

using namespace std;

// Allign all data on 2 byte boundaries
#pragma pack(2)

struct BitmapFileHeader{
  char header[2]{'B', 'M'};
  int32_t fileSize;
  int32_t reserved{0};
  int32_t dataOffset;
};

#endif //_BIT_MAP_FILE_HEADER_H_
