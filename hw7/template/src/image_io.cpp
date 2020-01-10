#include "image_io.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

/**
 * Implementation of `Image loadImage( const std::string & pathToRaw )` 
 * You should open the file corresponds to `pathToRaw`, and read the content of it.
 * The input file contains `m+1` lines, the first line contains two integer `m` and `n`
 * `m` is the number of lines, `n` is the number of columns of the matrix
 * For the next `m` lines, each line contains `n` integers, which are the pixels of image.
 * When load a image, you should divide each pixel by 255
 * E.g. if the matrix_file[i][j] = 128, then image[i][j] = 128.0f/255.0f
 * For a sample, you can refer to `soccer.txt` in directory `data`
 * @param pathToRaw: The image matrix file path, eg: `../data/soccer.txt`
 * @return: The image object load from TXT file
 */
Image
loadImage( const std::string & pathToRaw ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}

/**
 * Implementation of `void saveImage( Image & img, const std::string & pathToRaw )` 
 * You should open/create the file corresponds to `pathToRaw`, and write the given image to it.
 * The output file contains `m` lines
 * For the each line in `m` lines, it contains `n` floats, which are the pixels of image.
 * Each float ranges from 0 to 1.
 * @param img: The image object need to write.
 * @param pathToRaw: The image matrix file path, eg: `../data/soccer_derx.txt`
 */
void
saveImage( Image & img, const std::string & pathToRaw ) {
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}