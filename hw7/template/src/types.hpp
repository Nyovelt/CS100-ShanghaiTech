#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <Eigen/Eigen>

typedef Eigen::ArrayXXf Image;
typedef Eigen::ArrayXXf Kernel;

enum Filter {
  BLUR,
  DER_X,
  DER_Y,
  DER_MAG
};

#endif