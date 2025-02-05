#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
 *
 */

#include <iostream>
#include "./include/doctest.h"
#include "fisherYatesTopDown.h"

#include "Permutation.h"

using namespace std;

/*
  Testing
 */

int nums_0[] = {};
int nums_1[] = {1,2,3};
int nums_2[] = {1,1,-1,-1};
int nums_3[] = {-1,-1,1,1};

TEST_CASE("Swap Testing ") {
SUBCASE("swap test") {
    int a = 8, b = -5;
    swap(&a, &b);
    CHECK(a == -5);

    int nums[] = {1,2};
    int one_index_save = nums[1];
    int zero_index_save = nums[0];
    
    swap(& nums[0], & nums[1]);
    CHECK( nums[0]  == one_index_save );
    CHECK( nums[1]  == zero_index_save );
  };
};



int NOT_random_static_forward() {
  static int val = 0;
  return val++;
}



TEST_CASE("Testing fisher_yates top down function") {


  Permutation permutation;
  permutation.setValue(0);
  permutation.setDirection(permutation.INCREMENT);

  int init_list_0[] = {5,40};

  SUBCASE("fisher-yates-top-down basic tests NOT RANDOM") { // using fixed NON-random function

    cout << "Not random_0" << endl;
    
    show_data(init_list_0, sizeof(init_list_0)/sizeof(init_list_0[0]));

    cout << "  :  ";
    fisher_yates_top_down(init_list_0, sizeof(init_list_0)/sizeof(init_list_0[0]), permutation.getNext );// NOT_random_static_forward);
    
    show_data(init_list_0, sizeof(init_list_0)/sizeof(init_list_0[0]));

    cout << "\nNOT_random_0" << endl;    

    CHECK( 40 == init_list_0[0] );
    CHECK( 5 == init_list_0[1] );    
  };

};
  