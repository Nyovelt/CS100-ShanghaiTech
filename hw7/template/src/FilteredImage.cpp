#include "FilteredImage.hpp"
#include <iostream>


/**
 * Implementation of `FilteredImage::FilteredImage( Image & img )` 
 * This is a constructor of class FilteredImage, which is defined in `FilteredImage.hpp`
 * You should set the member variable `_img` as given parameter `img` 
 * @param img: The image that will be filtered
 */
FilteredImage::FilteredImage( Image & img ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}

/**
 * Implementation of `Image & FilteredImage::get( int type )`
 * This is a member function of class FilteredImage, which is defined in `FilteredImage.hpp`
 * You should refer to the documentation, finish 4 types of applications
 * Hint: The following 4 cases should be very similar. 
 * @param type: The type of Kernel
 */
Image &
FilteredImage::get( int type ) {
  switch( type ) {
    case BLUR: {
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      return /* Your result */;
    }
    case DER_X: {
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      return /* Your result */;
    }
    case DER_Y: {
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      return /* Your result */;
    }
    case DER_MAG: {
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      return /* Your result */;
    }
    default: {
      std::cout << "Error: unrecognized kernel option\n";
    }
  }
  return _img;
}

/**
 * Implementation of `void FilteredImage::applyKernel( Image & input, Image & output, Kernel & K )`
 * This is a member function of class FilteredImage, which is defined in `FilteredImage.hpp`
 * You should do convolution operation for the input image
 * That is, OUTPUT = INPUT * KERNEL, where `*` is the convolution operator 
 * @param input: The input image
 * @param output: The output image
 * @param kernel: The convolution kernel
 */
void
FilteredImage::applyKernel( Image & input, Image & output, Kernel & K ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}