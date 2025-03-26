#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ints_read_matrix.h"



TEST_CASE("ints_read_matrix") {
  
  SUBCASE("ints_read_matrix : edge cases - istringstream") {
    istringstream istr_0("");
    vector<vector<int>> matrix_0 = ints_read_matrix(istr_0);
    CHECK(1 == matrix_0.size());
  
    istringstream istr_99("-99");
    vector<vector<int>> matrix_99 = ints_read_matrix(istr_99);
    CHECK(-99 == matrix_99[0][0]);
    CHECK(1 == matrix_99.size());
    CHECK(1 == matrix_99[0].size());
  };
  
  SUBCASE("ints_read_matrix : small cases") {

    istringstream istr("0 1 2\n4 5 6\n7 8 9");
    vector<vector<int>> matrix = ints_read_matrix(istr);
    CHECK(0 == matrix[0][0]);
    CHECK(1 == matrix[0][1]);
    CHECK(2 == matrix[0][2]);
    CHECK(3 == matrix.size());
    CHECK(3 == matrix[0].size());
    CHECK(3 == matrix[2].size());

  };
}
