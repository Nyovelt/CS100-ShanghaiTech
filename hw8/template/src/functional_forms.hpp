#ifndef FUNCTIONAL_FORMS_HPP_
#define FUNCTIONAL_FORMS_HPP_

#include <stdlib.h>
#include <math.h>

/* For all lambda functions below, if you are not clear how they work, please refer to the given example for details. */


/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1+f2)(m) as first, and (d(f1+f2)/dx)(m) as second.
 */
auto derSum = []( auto f1, auto f2 ){
  return [=](double param)
  {
    auto f1x = f1(param);
    auto f2x = f2(param);
    return std::pair<double, double>(f1x + f2x, f1->der()(param) + f2->der()(param));
  }
  //add your code here ...
};


/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1-f2)(m) as first, and (d(f1-f2)/dx)(m) as second.
 */
auto derSub = []( auto f1, auto f2 ){
  return [=](double param)
  {
    auto f1x = f1(param);
    auto f2x = f2(param);
    return std::pair<double, double>(f1x - f2x, f1->der()(param) - f2->der()(param));
  }
  //add your code here ...
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1*f2)(m) as first, and (d(f1*f2)/dx)(m) as second.
 */
auto derMul = []( auto f1, auto f2 ){
    return [=](double param)
  {
    auto f1x = f1(param);
    auto f2x = f2(param);
    return std::pair<double, double>(f1x * f2x, f1->der()(param) * f2(param) + f2->der()(param) * f1(param));
  }
  //add your code here ...
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1/f2)(m) as first, and (d(f1/f2)/dx)(m) as second.
 */
auto derDiv = []( auto f1, auto f2 ){
    return [=](double param)
  {
    auto f1x = f1(param);
    auto f2x = f2(param);
    return std::pair<double, double>(f1x / f2x, (f1->der()(param) * f2(param) - f2->der()(param) * f1(param)) 
                                                / (f2x * f2x) );
  }
  //add your code here ...
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1(f2))(m) as first, and (d(f1(f2))/dx)(m) as second.
 */
auto derComp = []( auto f1, auto f2 ){
  return [=](double param)
  {
    return std::pair<double, double>(f1(f2(param)) ,  );
  }
  //add your code here ...
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has [(f1)(m)]^exp as first, and (d(f1^exp)/dx)(m) as second.
 */
auto derPow = []( auto f, int exp ) {
  //add your code here ...
};

#endif