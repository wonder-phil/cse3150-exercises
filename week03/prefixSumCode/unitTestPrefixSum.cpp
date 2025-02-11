#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  DOCTest unit tests
 */

#include "../include/doctest.h"
#include "prefixSum.h"

int nums_0[] = {};
int nums_1[] = {-5};
int non_neg_prefix_sum_nums_2[] = {1,-1};
int nums_3[] = {2,-3,3,2};
int nums_4[] = {1,1,-1,1};
int nums_5[] = {-1,-1,-1,-1,1,1};



TEST_CASE("Test week1/2 functions") {
  SUBCASE("non-negative prefix sums") {

    CHECK(non_negative_prefix_sum(non_neg_prefix_sum_nums_2, 2));
    CHECK_FALSE(non_positive_prefix_sum(non_neg_prefix_sum_nums_2, 2));

  };
  SUBCASE("non-positive prefix sums") {

  };
}