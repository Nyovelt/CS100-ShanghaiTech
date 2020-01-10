#ifndef THREADEDFILTEREDIMAGE_HPP_
#define THREADEDFILTEREDIMAGE_HPP_

#include <stdlib.h>
#include "FilteredImage.hpp"
#include "types.hpp"

class ThreadedFilteredImage : public FilteredImage {
public:
  ThreadedFilteredImage( Image & img, int numberThreads = 8 );

private:
  virtual void applyKernel( Image & input, Image & output, Kernel & K );
  void applyKernelThread( int startingCol, Image & input, Image & output, Kernel & K );

  int _numberThreads;
};

#endif