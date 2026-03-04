#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "../include/doctest.h" 

#include "date.h"

 

TEST_CASE("testing the Date class") { 

  Date firstDate(1,4,2026);

  

  CHECK(firstDate.getDay() == 1);   
  CHECK(firstDate.getMonth() == 4); 
  CHECK(firstDate.getYear() == 2026); 

} 


TEST_CASE("testing the Date class") { 

  Date secondDate(31,12,2026);
  secondDate.IsoOutput();

  CHECK(secondDate.getDay() == 31);   
  CHECK(secondDate.getMonth() == 12); 
  CHECK(secondDate.getYear() == 2026); 

  secondDate.add_days(4);

  CHECK(secondDate.getDay() == 4);   
  CHECK(secondDate.getMonth() == 1); 
  CHECK(secondDate.getYear() == 2027); 

  Date thirdDate(1,9,2026);
  thirdDate.IsoOutput();

} 

 