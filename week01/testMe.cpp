#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "./include/doctest.h" 

 

int factorial(int number) { 
  if( number <= 1 ) { 
    return 1; 
  } else { 
    return number * factorial(number - 1); 
  } 

} 

 

TEST_CASE("testing the factorial function") { 

  CHECK(factorial(0) == 1);   
  CHECK(factorial(1) == 1); 
  CHECK(factorial(2) == 2); 
  CHECK(factorial(3) == 6); 
  CHECK(factorial(3.5) == 6); // Do they indend to call the Gamma function?
  CHECK_FALSE(factorial(4) == 25);
  CHECK(factorial(10) == 3628800); 

} 

 