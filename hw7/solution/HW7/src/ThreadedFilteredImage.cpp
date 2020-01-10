#include "ThreadedFilteredImage.hpp"
#include <vector>
#include <thread>


ThreadedFilteredImage::ThreadedFilteredImage( Image & img, int numberThreads ) : FilteredImage( img ), _numberThreads(numberThreads)
{}

void
ThreadedFilteredImage::applyKernel( Image & input, Image & output, Kernel & K ) {
  std::vector<std::thread> kernelApplicators;
  kernelApplicators.reserve(_numberThreads);
  for( size_t i = 0; i < _numberThreads; i++ )
    kernelApplicators.emplace_back(std::bind(&ThreadedFilteredImage::applyKernelThread,this,i,std::ref(input),std::ref(output),std::ref(K)));

  for( auto& thread : kernelApplicators ) {
    if( thread.joinable() )
      thread.join();
  }
}

void
ThreadedFilteredImage::applyKernelThread( int startingCol, Image & input, Image & output, Kernel & K ) {
  int halfKernelHeight = (K.rows() - 1) / 2;
  int halfKernelWidth = (K.cols() - 1) / 2;

  for( int r = halfKernelHeight+startingCol; r < input.rows()-halfKernelHeight; r += _numberThreads ) {
    for( int c = halfKernelWidth; c < input.cols()-halfKernelWidth; c++ ) {
      output(r,c) = (input.block(r-halfKernelHeight,c-halfKernelWidth,K.rows(),K.cols()) * K).sum();
    }
  }
}