#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include <iostream>
#include "./include/doctest.h"
#include "simulatePosNeg.h"

using namespace std;

/*
  Testing
 */

int nums_0[] = {};
int nums_2[] = {1,-1};
int nums_2reverse[] = {-1,1};
int nums_4[] = {1,1,-1,-1};
int nums_4reverse[] = {-1,-1,1,1};

TEST_CASE("Testing unit-test functions") {

  SUBCASE("setupPlusAndMinuses") {
    setupPlusAndMinuses(nums_2, 1);
    CHECK( nums_2[0] == 1 );
    CHECK( nums_2[1] == -1 );

    setupPlusAndMinuses(nums_2reverse, 1);
    CHECK( nums_2reverse[0] == 1 );
    CHECK( nums_2reverse[1] == -1 );
  };

SUBCASE("both_pos_and_neg") {
    setupPlusAndMinuses(nums_2, 1);
    CHECK( 0 == both_pos_and_neg(nums_2, 10, 1) ); // +1, -1 which only has non-negative prefix sums

    CHECK( 0 == both_pos_and_neg(nums_2reverse, 10, 1) ); // -1, +1 which only has non-positive prefix sums
  };
  
  

};
