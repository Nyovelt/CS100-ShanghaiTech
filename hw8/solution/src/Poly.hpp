#ifndef POLY_HPP_
#define POLY_HPP_

#include <stdlib.h>
#include <vector>

template<typename T>
class Poly {
public:
  Poly();
  Poly( T constant );
  Poly( const std::vector<T> & coeffs );
  Poly( std::vector<T> && coeffs );
  Poly( T * coeffs, size_t numberCoeffs );
  Poly( std::initializer_list<T> coeffs );
  virtual ~Poly();

  Poly( const Poly<T> & poly );
  Poly( Poly<T> && poly );

  Poly<T>& operator=( const Poly<T> & poly );
  Poly<T>& operator=( Poly<T> && poly );

  Poly<T> operator+( const Poly<T> & rhs ) const;
  Poly<T> operator-( const Poly<T> & rhs ) const;
  Poly<T> operator*( const Poly<T> & rhs ) const;

  Poly<T> & operator+=( const Poly<T> & rhs );
  Poly<T> & operator-=( const Poly<T> & rhs );
  Poly<T> & operator*=( const Poly<T> & rhs );

  T eval( T param ) const;
  Poly<T> der() const;
  std::pair<T,T> operator()( T param ) const;

private:
  std::vector<T> _coeffs;
};

#include "Poly_impl.hpp"

#endif