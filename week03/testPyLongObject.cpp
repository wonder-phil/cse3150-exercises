#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "./include/doctest.h" 

#include "PyLongObject.h"

 


 

TEST_CASE("testing the factorial function") { 

  PyLongObject pyLongObject(0);

  CHECK(pyLongObject.getSmallValue() == 0);   
  
} 

 