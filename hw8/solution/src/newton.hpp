#ifndef GAUSS_NEWTON_HPP_
#define GAUSS_NEWTON_HPP_

#include <stdlib.h>

template<typename T>
double findNearestRoot( T f, double startingPoint, double eps = 0.000001 ) {
  double optimizationPoint = startingPoint;
  bool converged = false;
  while( !converged ) {
    std::pair<double,double> value = f(optimizationPoint);
    double delta = -value.first/value.second;
    optimizationPoint += delta;
    if( fabs(delta) < eps )
      converged = true;
  }
  return optimizationPoint;
}

#endif