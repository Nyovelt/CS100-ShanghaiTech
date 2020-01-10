#include "Poly.hpp"

#include <iostream>
#include <math.h>

typedef double TYPE;

void doTest( const Poly<TYPE> & poly, TYPE param, TYPE expectation ) {
  TYPE result = poly.eval(param)-expectation;
  if( fabs(result) > 0.000001 )
    std::cout << "Error!\n";
  else
    std::cout << "Success!\n";
}

int main() {
  
  //testing interface of the polynomial class

  //constructors
  Poly<TYPE> p1;                                      doTest(p1,10,0);
  Poly<TYPE> p2(2);                                   doTest(p2,10,2);
  std::vector<TYPE> cs{ 0, 1, 0, -2};
  Poly<TYPE> p3(cs);                                  doTest(p3,2,-14);
  Poly<TYPE> p4(std::vector<TYPE>(3,1));              doTest(p4,3,13);
  TYPE arr[] = {1,0,2};
  Poly<TYPE> p5(arr,3);                               doTest(p5,3,19);
  Poly<TYPE> p6{2,0,-1};                              doTest(p6,3,-7);
  
  //copy/move constructor
  Poly<TYPE> p7(p3);                                  doTest(p7,2,-14);
  Poly<TYPE> p8(Poly<TYPE>(std::vector<TYPE>(3,1)));  doTest(p8,3,13);

  //assignments
  p8 = p7;                                            doTest(p8,2,-14);
  p8 = Poly<TYPE>{2,0,-1};                            doTest(p8,3,-7);

  //operations
  Poly<TYPE> p9 = p3 + p4;                            doTest(p9,2,-7);
  Poly<TYPE> p10 = p9 - p3;                           doTest(p10,3,13);
  p10 *= p9;
  TYPE res1 = p10.eval(-4);
  TYPE res2 = p4.eval(-4) * p9.eval(-4);
  if( fabs(res1-res2) < 0.000001 )
    std::cout << "Success!\n";
  else
    std::cout << "Error!\n";

  //evaluators
  doTest(p4.der(),2,5);
  std::pair<TYPE,TYPE> res = p4(2);
  if(fabs(res.first-7)<0.000001)
    std::cout << "Success!\n";
  else
    std::cout << "Error!\n";
  if(fabs(res.second-5)<0.000001)
    std::cout << "Success!\n";
  else
    std::cout << "Error!\n";
}