#include <stdlib.h>
#include <string>
#include "types.hpp"
#include "image_io.hpp"


int main( int argc, char ** argv ) {

  //the program expects two parameters
  //1: the directory to the data (without trailing '/')
  //2: the name of the input image file (without trailing ".txt")

  std::string inputImage = std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string(".txt");
  Image img = loadImage(inputImage);
  saveImage(img, std::string(argv[1]) + std::string("/") + std::string(argv[2]) + std::string("_testio.txt"));

  return 0;
}