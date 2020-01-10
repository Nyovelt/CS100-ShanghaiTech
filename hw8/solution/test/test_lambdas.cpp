#include "Poly.hpp"
#include "functional_forms.hpp"

#include <iostream>
#include <math.h>

int main() {
  
  double testPoint = 0.1;

  //get the value and derviative using the functional composition forms
  Poly<double> p1{1,2,3}, p2{1,2,3}, p3{1,2,3}, p4{1,2,3}, p5{1,2,3}, p6{1,2,3};
  auto g = derDiv(derSub(derPow(derComp(p1,p2),3),p3),derSum(p4,derMul(p5,p6)));
  std::pair<double,double> result = g(testPoint);
  std::cout << result.first << " " << result.second << std::endl;

  //get the value and derivative using the alternative ways
  double epsilon = 0.0000001;
  double numerator = pow(p2.eval(p1.eval(testPoint)),3.0)-p3.eval(testPoint);
  double denominator = p4.eval(testPoint) + p5.eval(testPoint) * p6.eval(testPoint);
  double value = numerator/denominator;
  std::cout << value << " ";
  testPoint += epsilon;
  numerator = pow(p2.eval(p1.eval(testPoint)),3.0)-p3.eval(testPoint);
  denominator = p4.eval(testPoint) + p5.eval(testPoint) * p6.eval(testPoint);
  double grad = (numerator/denominator-value)/epsilon;
  std::cout << grad << std::endl;
}