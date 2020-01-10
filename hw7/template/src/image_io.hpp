#ifndef IMAGE_IO_HPP_
#define IMAGE_IO_HPP_

#include <stdlib.h>
#include <string>
#include "types.hpp"

Image loadImage( const std::string & pathToRaw );
void saveImage( Image & img, const std::string & pathToRaw );

#endif