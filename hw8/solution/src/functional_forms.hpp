#ifndef FUNCTIONAL_FORMS_HPP_
#define FUNCTIONAL_FORMS_HPP_

#include <stdlib.h>
#include <math.h>

auto derSum = []( auto f1, auto f2 ){
  return [=]( double input ){
    std::pair<double,double> res1 = f1(input);
    std::pair<double,double> res2 = f2(input);
    return std::pair<double,double>(
      res1.first+res2.first,
      res1.second+res2.second );
  };
};

auto derSub = []( auto f1, auto f2 ){
  return [=]( double input ){
    std::pair<double,double> res1 = f1(input);
    std::pair<double,double> res2 = f2(input);
    return std::pair<double,double>(
      res1.first-res2.first,
      res1.second-res2.second );
  };
};

auto derMul = []( auto f1, auto f2 ){
  return [=]( double input ){
    std::pair<double,double> res1 = f1(input);
    std::pair<double,double> res2 = f2(input);
    return std::pair<double,double>(
      res1.first * res2.first,
      res1.second * res2.first + res1.first * res2.second );
  };
};

auto derDiv = []( auto f1, auto f2 ){
  return [=]( double input ){
    std::pair<double,double> res1 = f1(input);
    std::pair<double,double> res2 = f2(input);
    return std::pair<double,double>(
      res1.first/res2.first,
      (res1.second*res2.first - res1.first*res2.second)/(res2.first*res2.first));
  };
};

auto derComp = []( auto f1, auto f2 ){
  return [=]( double input ){
    std::pair<double,double> res1 = f1(input);
    std::pair<double,double> res2 = f2(res1.first);
    return std::pair<double,double>(
      res2.first,
      res2.second*res1.second);
  };
};

auto derPow = []( auto f, int exp ) {
  return [=]( double input ){
    std::pair<double,double> res = f(input);
    return std::pair<double,double>(
      pow(res.first,exp),
      exp*pow(res.first,exp-1)*res.second);
  };
};

#endif