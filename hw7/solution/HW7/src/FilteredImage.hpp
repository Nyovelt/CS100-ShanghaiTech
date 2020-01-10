#ifndef FILTEREDIMAGE_HPP_
#define FILTEREDIMAGE_HPP_

#include <stdlib.h>
#include <map>
#include <memory>

#include "types.hpp"

class FilteredImage {
public:
  FilteredImage( Image & img );
  Image & get( int type );

private:
  virtual void applyKernel( Image & input, Image & output, Kernel & K );

  Image & _img;
  std::map< int, std::shared_ptr<Image> > _filteredImages;
};

#endif