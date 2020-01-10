#include "image_io.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>

Image
loadImage( const std::string & pathToRaw ) {
  std::ifstream input(pathToRaw);
  std::string oneLine;
  std::getline( input, oneLine );
  std::stringstream sss(oneLine);
  int rows,cols;
  sss >> rows >> cols;

  Image img(rows, cols);
  int row = 0;

  while(input.good()) {
    std::getline( input, oneLine );
    std::stringstream ss(oneLine);

    int col = 0;

    while( ss.good() ) {
      int value = 0;
      ss >> value;
      img(row,col++) = (float) value / 255.0f;
    }
    row++;
  }

  return img;
}

void
saveImage( Image & img, const std::string & pathToRaw ) {
  std::ofstream output(pathToRaw);

  for( int r = 0; r < img.rows(); r++ ) {
    for( int c = 0; c < img.cols(); c++ )
      output << img(r,c) << " ";
    if( r != img.rows()-1 )
      output << "\n";
  }

  output.close();
}