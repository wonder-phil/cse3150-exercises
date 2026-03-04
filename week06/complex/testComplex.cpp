#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "../include/doctest.h" 

#include "Complex.h"

 

TEST_CASE("Default constructor") { 

  const double _real{0.0}, _img{0.0};
  Complex complex;

  CHECK(complex.getReal() == _real);   
  CHECK(complex.getImag() == _img); 
} 

TEST_CASE("Custom constructor") { 

  const double _real{4.3}, _img{4.0};
  Complex complex(_real, _img);

  CHECK(complex.getReal() == _real);   
  CHECK(complex.getImag() == _img); 
} 

TEST_CASE("Copy constructor") { 

  const double _real{4.3}, _img{4.0};
  Complex complex(_real, _img), otherComplex;

  otherComplex = complex;

  CHECK(complex.getReal() == otherComplex.getReal());
  CHECK(complex.getImag() == otherComplex.getImag());

} 


TEST_CASE("Complex assignment constructor") { 

  const double _real{4.3}, _img{4.0};
  const double _realZero{0.0};

  Complex complex(_real, _img);

  Complex other;
  CHECK(other.getReal() == _realZero);   
  CHECK(other.getImag() == _realZero);   

  other = complex;
  CHECK(complex.getReal() == other.getReal());   
  CHECK(complex.getImag() == other.getImag()); 
} 

TEST_CASE("Complex == and != test") { 

  const double _real{4.3}, _img{4.0};
  
  Complex complex(_real, _img);
  Complex copyComplex = complex;

  Complex notEqual(_real + 2.0, _img - 1.7);

  CHECK(copyComplex.getReal() == complex.getReal());   
  CHECK(copyComplex.getImag() == complex.getImag());   

  CHECK_FALSE(complex == notEqual);   
  CHECK(complex != notEqual);
} 
