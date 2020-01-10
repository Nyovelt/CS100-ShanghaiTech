#include "Poly.hpp"
#include "functional_forms.hpp"
#include "newton.hpp"

#include <iostream>

int main() {
  //get the function that we want to handle here
  Poly<double> p1{1,-2,3,-4}, p2{3,2,1};
  auto g = derDiv(p1,p2);

  //find the root
  double testPoint = 0.0;
  double nearestRoot = findNearestRoot( g, testPoint );
  std::cout << "The nearest root is: " << nearestRoot;
  std::cout << " and the value here is " << g(nearestRoot).first << std::endl;
}