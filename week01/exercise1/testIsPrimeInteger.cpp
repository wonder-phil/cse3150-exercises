#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "../include/doctest.h" 

#include "isPrimeFunction.h"



TEST_CASE("testing the factorial function") { 

  CHECK(isPrimeInteger(101));   
  CHECK_FALSE(isPrimeInteger(102));   

  //CHECK(isPrimeInteger(0) == 1);   


};