#include "FilteredImage.hpp"
#include <iostream>


FilteredImage::FilteredImage( Image & img ) : _img(img)
{}

Image &
FilteredImage::get( int type ) {
  switch( type ) {
    case BLUR: {
      if( !_filteredImages[BLUR] ) {
        Kernel K(5,5);
        K << (2.0f/159.0f), ( 4.0f/159.0f), ( 5.0f/159.0f), ( 4.0f/159.0f), (2.0f/159.0f),
             (4.0f/159.0f), ( 9.0f/159.0f), (12.0f/159.0f), ( 9.0f/159.0f), (4.0f/159.0f),
             (5.0f/159.0f), (12.0f/159.0f), (15.0f/159.0f), (12.0f/159.0f), (5.0f/159.0f),
             (4.0f/159.0f), ( 9.0f/159.0f), (12.0f/159.0f), ( 9.0f/159.0f), (4.0f/159.0f),
             (2.0f/159.0f), ( 4.0f/159.0f), ( 5.0f/159.0f), ( 4.0f/159.0f), (2.0f/159.0f);
        std::shared_ptr<Image> blurredImg( new Image(_img.rows(),_img.cols()) );
        blurredImg->fill(0.0);
        applyKernel(_img,*blurredImg,K);
        _filteredImages[BLUR] = blurredImg;
      }
      return *_filteredImages[BLUR];
      break;
    }
    case DER_X: {
      if( !_filteredImages[DER_X] ) {
        Kernel K(3,3);
        K << -1.0f, 0.0f, 1.0f,
             -2.0f, 0.0f, 2.0f,
             -1.0f, 0.0f, 1.0f;
        std::shared_ptr<Image> derXImg( new Image(_img.rows(),_img.cols()) );
        derXImg->fill(0.0);
        applyKernel(_img,*derXImg,K);
        _filteredImages[DER_X] = derXImg;
      }
      return *_filteredImages[DER_X];
      break;
    }
    case DER_Y: {
      if( !_filteredImages[DER_Y] ) {
        Kernel K(3,3);
        K << -1.0f, -2.0f, -1.0f,
              0.0f,  0.0f,  0.0f,
              1.0f,  2.0f,  1.0f;
        std::shared_ptr<Image> derYImg( new Image(_img.rows(),_img.cols()) );
        derYImg->fill(0.0);
        applyKernel(_img,*derYImg,K);
        _filteredImages[DER_Y] = derYImg;
      }
      return *_filteredImages[DER_Y];
      break;
    }
    case DER_MAG: {
      if( !_filteredImages[DER_MAG] ) {
        Image & der_x = this->get( DER_X );
        Image & der_y = this->get( DER_Y );
        std::shared_ptr<Image> derMagImg( new Image(der_x*der_x+der_y*der_y) );
        Image & derMagImgRef = *derMagImg;
        for( int r = 0; r < derMagImgRef.rows(); r++ ) {
          for( int c = 0; c < derMagImgRef.cols(); c++ )
            derMagImgRef(r,c) = sqrt(derMagImgRef(r,c));
        }
        _filteredImages[DER_MAG] = derMagImg;
      }
      return *_filteredImages[DER_MAG];
      break;
    }
    default: {
      std::cout << "Error: unrecognized kernel option\n";
      return _img;
    }
  }
}

void
FilteredImage::applyKernel( Image & input, Image & output, Kernel & K ) {
  int halfKernelHeight = (K.rows() - 1) / 2;
  int halfKernelWidth = (K.cols() - 1) / 2;

  for( int r = halfKernelHeight; r < input.rows()-halfKernelHeight; r++ ) {
    for( int c = halfKernelWidth; c < input.cols()-halfKernelWidth; c++ ) {
      output(r,c) = (input.block(r-halfKernelHeight,c-halfKernelWidth,K.rows(),K.cols()) * K).sum();
    }
  }
}