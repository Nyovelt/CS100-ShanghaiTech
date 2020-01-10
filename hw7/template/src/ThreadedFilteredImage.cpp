#include "ThreadedFilteredImage.hpp"
#include <vector>
#include <thread>

/**
 * Implementation of `ThreadedFilteredImage::ThreadedFilteredImage( Image & img, int numberThreads )` 
 * This is a constructor of class ThreadedFilteredImage, which is defined in `ThreadedFilteredImage.h`
 * You should set the member variable `_img` as given parameter `img` 
 * You should set the member variable `_numberThreads` as given parameter `numberThreads` 
 * @param img: The image that will be filtered
 * @param numberThreads: The number of threads to use
 */
ThreadedFilteredImage::ThreadedFilteredImage( Image & img, int numberThreads ){
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}

/**
 * Implementation of `void ThreadedFilteredImage::applyKernel( Image & input, Image & output, Kernel & K )`
 * It's the similar as `applyKernel` in `class FilteredImage`
 * But you need to do that job using parallelism (using `# of threads = _numberThreads`)
 * You will found these functions / classes are useful:
 * `std::vector<T>`, `std::thread`, `std::bind()`, `std::thread::join()`, `std::thread::joinable()`
 */
void
ThreadedFilteredImage::applyKernel( Image & input, Image & output, Kernel & K ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}

/**
 * For parallelism, you will need to divide the image into `k` different parts
 * Which `k` is the number of threads.
 * This function is each thread's job
 * A simple idea is, divide the image by column.
 * It should start from `startingCol`, ends at `startingCol + (totalCol / numThreads)`
 * It's similar as `applyKernelThread` in `class FilteredImage`
 * But now, you should not convolute the whole image, just a part of that.
 */
void
ThreadedFilteredImage::applyKernelThread( int startingCol, Image & input, Image & output, Kernel & K ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}