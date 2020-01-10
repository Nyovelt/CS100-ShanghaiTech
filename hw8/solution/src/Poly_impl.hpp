template<typename T>
Poly<T>::Poly() {
  _coeffs.push_back(0);
}

template<typename T>
Poly<T>::Poly( T constant ) {
  _coeffs.push_back(constant);
}

template<typename T>
Poly<T>::Poly( const std::vector<T> & coeffs ) : _coeffs(coeffs) {}

template<typename T>
Poly<T>::Poly( std::vector<T> && coeffs ) : _coeffs(coeffs) {}

template<typename T>
Poly<T>::Poly( T * coeffs, size_t numberCoeffs ) {
  for(int i = 0; i < numberCoeffs; i++) _coeffs.push_back(coeffs[i]);
}

template<typename T>
Poly<T>::Poly( std::initializer_list<T> coeffs ) {
  for( auto i : coeffs ) _coeffs.push_back(i);
}

template<typename T>
Poly<T>::~Poly() {}

template<typename T>
Poly<T>::Poly( const Poly<T> & poly ) {
  _coeffs = poly._coeffs;
}

template<typename T>
Poly<T>::Poly( Poly<T> && poly ) {
  _coeffs = std::move(poly._coeffs);
  poly._coeffs.clear();
  poly._coeffs.push_back(0);
}

template<typename T>
Poly<T>&
Poly<T>::operator=( const Poly<T> & poly ) {
  _coeffs = poly._coeffs;
  return *this;
}

template<typename T>
Poly<T>&
Poly<T>::operator=( Poly<T> && poly ) {
  _coeffs = std::move(poly._coeffs);
  poly._coeffs.clear();
  poly._coeffs.push_back(0);
  return *this;
}

template<typename T>
Poly<T>
Poly<T>::operator+( const Poly<T> & rhs ) const {
  Poly<T> res(_coeffs);
  res += rhs;
  return res;
}

template<typename T>
Poly<T>
Poly<T>::operator-( const Poly<T> & rhs ) const {
  Poly<T> res(_coeffs);
  res -= rhs;
  return res;
}

template<typename T>
Poly<T>
Poly<T>::operator*( const Poly<T> & rhs ) const {
  size_t finalSize = (_coeffs.size()-1) + (_coeffs.size()-1) + 1;
  Poly<T> res( std::vector<T>(finalSize,0) );

  size_t degree1 = 0;
  for( auto i1 : _coeffs ) {
    size_t degree = degree1;
    for( auto i2 : rhs._coeffs ) {
      res._coeffs[degree] += i1*i2;
      degree++;
    }
    degree1++;
  }

  return res;
}

template<typename T>
Poly<T> &
Poly<T>::operator+=( const Poly<T> & rhs ) {
  if( _coeffs.size() < rhs._coeffs.size() )
    _coeffs.resize(rhs._coeffs.size(),0);
  size_t i = 0;
  for( auto c : rhs._coeffs )
    _coeffs[i++] += c;

  return *this;
}

template<typename T>
Poly<T> &
Poly<T>::operator-=( const Poly<T> & rhs ) {
  if( _coeffs.size() < rhs._coeffs.size() )
    _coeffs.resize(rhs._coeffs.size(),0);
  size_t i = 0;
  for( auto c : rhs._coeffs )
    _coeffs[i++] -= c;

  return *this;
}

template<typename T>
Poly<T> &
Poly<T>::operator*=( const Poly<T> & rhs ) {
  Poly<T> res = *this * rhs;
  _coeffs = std::move(res._coeffs);
  return *this;
}

template<typename T>
T
Poly<T>::eval( T param ) const {
  T result = 0;
  T accumulator = 1;
  for( int i = 0; i < _coeffs.size(); i++ ) {
    result += _coeffs[i] * accumulator;
    accumulator *= param;
  }
  return result;
}

template<typename T>
Poly<T>
Poly<T>::der() const {
  if( _coeffs.size() < 2 )
    return Poly<T>();

  Poly<T> res( std::vector<T>(_coeffs.size()-1,0) );
  for( int i = 1; i < _coeffs.size(); i++ )
    res._coeffs[i-1] = i*_coeffs[i];

  return res;
}

template<typename T>
std::pair<T,T>
Poly<T>::operator()( T param ) const {
  return std::pair<T,T>( eval(param), der().eval(param) );
};