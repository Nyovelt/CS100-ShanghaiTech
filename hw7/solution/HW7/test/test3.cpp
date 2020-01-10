#include <stdlib.h>
#include <string>
#include "types.hpp"
#include "image_io.hpp"
#include "ThreadedFilteredImage.hpp"


int main( int argc, char ** argv ) {

  //the program expects two parameters
  //1: the directory to the data (without trailing '/')
  //2: the name of the input image file (without trailing ".txt")

  std::string inputImage = std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string(".txt");
  Image img = loadImage(inputImage);

  ThreadedFilteredImage fimg(img);
  Image & blurredImg = fimg.get(BLUR);
  Image & derxImg = fimg.get(DER_X);
  Image & deryImg = fimg.get(DER_Y);
  Image & derMagImg = fimg.get(DER_MAG);

  saveImage(blurredImg, std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string("_blurred.txt"));
  saveImage(derxImg, std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string("_derx.txt"));
  saveImage(deryImg, std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string("_dery.txt"));
  saveImage(derMagImg, std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string("_dermag.txt"));

  return 0;
}