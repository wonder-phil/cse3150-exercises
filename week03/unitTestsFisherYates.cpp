#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include <iostream>
#include "./include/doctest.h"
#include "fisherYates.h"

using namespace std;

bool in_list(int list[], const int length, const int value) {
  bool is_in_list = false;
  for (int i=0; i < length; i++) {
    if (value == list[i]) {
      is_in_list = true;
      break;
    }
  }
  
  return is_in_list;
}

bool exactly_one_in_list(int list[], const int length, const int value) {
  bool one_in_list = false;

  for (int i=0; i < length; i++) {
    if (value == list[i]) {
      if ( one_in_list ) { // More than 1 in list!
	one_in_list = false;
	break;
      } else {
	one_in_list = true;
      }
    }
  }

  return one_in_list;
}

/*
  Testing
 */

int nums_0[] = {};
int nums_1[] = {1,2,3};
int nums_2[] = {1,1,-1,-1};
int nums_3[] = {-1,-1,1,1};

TEST_CASE("Testing unit-test functions") {

  SUBCASE("in_list test") {
    int lst[] ={ 1,2,3 };
    CHECK( in_list(lst, sizeof(lst)/sizeof(lst[0]), lst[0] ));
    CHECK( in_list(lst, sizeof(lst)/sizeof(lst[0]), lst[1] ));
    CHECK( in_list(lst, sizeof(lst)/sizeof(lst[0]), lst[2] ));
    CHECK_FALSE( in_list(lst, sizeof(lst)/sizeof(lst[0]), 0 ) );                
    CHECK_FALSE( in_list(lst, sizeof(lst)/sizeof(lst[0]), -55 ) );            
  };

  SUBCASE("exactly_one_in_list test") {
    int lst_0[] ={};
    CHECK_FALSE( exactly_one_in_list(lst_0, sizeof(lst_0)/sizeof(lst_0[0]), 0 ));

    int lst_1[] ={ 1,2,3, 1 };
    CHECK_FALSE( exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), lst_1[0] )); // lst_1[0] == lst_1[3]
    CHECK( exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), lst_1[1] ));
    CHECK( exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), lst_1[2] ));
    CHECK_FALSE( exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), 0 ) );                
    CHECK_FALSE( exactly_one_in_list(lst_1, sizeof(lst_1)/sizeof(lst_1[0]), -55 ) );
  };

};

int not_random_swaps_0[] = {1,0};
int not_random_swaps_1[] = {3,2,1};
int not_random_swaps_2[] = {3,2,1};
int init_list_0[] = {5,40};
int init_list_1[] = {1,2,3,4};
int init_list_2[] = {1,2,3,4,5};


int r_index = 0;

int NOT_random_0() {
  return not_random_swaps_0[r_index++];
}

int NOT_random_1() {
  return not_random_swaps_1[r_index++];
}

int NOT_random_2() {
  return not_random_swaps_2[r_index++];
}


TEST_CASE("Testing fisher_yates function") {

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

  SUBCASE("fisher-yates basic tests NOT RANDOM") { // using fixed NON-random function

    cout << "Not random_0" << endl;
    
    show_data(init_list_0, sizeof(init_list_0)/sizeof(init_list_0[0]));
    cout << "  :  ";
    fisher_yates(init_list_0, sizeof(init_list_0)/sizeof(init_list_0[0]), NOT_random_0);
    show_data(init_list_0, sizeof(init_list_0)/sizeof(init_list_0[0]));

    cout << "\nNOT_random_0" << endl;    

    CHECK( 40 == init_list_0[0] );
    CHECK( 5 == init_list_0[1] );    

    /*
      not_random_swaps[] = {1,0};
      i=0 [5,40] ---> [40,5]

      Output [40,5]
     */


    r_index = 0;
    cout << "NOT_random_1" << endl;
    
    show_data(init_list_1, sizeof(init_list_1)/sizeof(init_list_1[0]));
    cout << "  :  ";
    fisher_yates(init_list_1, sizeof(init_list_1)/sizeof(init_list_1[0]), NOT_random_1);
    show_data(init_list_1, sizeof(init_list_1)/sizeof(init_list_1[0]));

    cout << "\nNOT_random_1" << endl;    

    CHECK( 4 == init_list_1[0] );
    CHECK( 1 == init_list_1[1] );    
    CHECK( 2 == init_list_1[2] );
    CHECK( 3 == init_list_1[3] );    
    /*
      not_random_swaps[] = {3,2,1};
      i=0 [1,2,3,4] ---> [_4_, 2, 3, _1_]
      i=1 [4,2,3,1] ---> [4, _1_, 3, _2_]       
      i=2 [4,1,3,2] ---> [4, 1, _2_, _3_]       

      Output [4,1,2,3]
     */

    r_index = 0;
    cout << "NOT_random_2" << endl;
    
    show_data(init_list_2, sizeof(init_list_2)/sizeof(init_list_2[0]));
    cout << "  :  ";
    fisher_yates(init_list_2, sizeof(init_list_2)/sizeof(init_list_2[0]), NOT_random_2);
    show_data(init_list_2, sizeof(init_list_2)/sizeof(init_list_2[0]));

    cout << "\nNOT_random_2" << endl;    

    /*
      not_random_swaps[] = {3,2,1};
      i=0 [1,2,3,4] ---> [_4_, 2, 3, _1_]
      i=1 [4,2,3,1] ---> [4, _1_, 3, _2_]       
      i=2 [4,1,3,2] ---> [4, 1, _2_, _3_]       

      Output [4,1,2,3]
     */


  };

  SUBCASE("fisher-yates basic tests std::rand") { // using std::rand
    const int bad_val = nums_0[0];
    fisher_yates(nums_0, sizeof(nums_0)/sizeof(nums_0[0]), std::rand);
    CHECK( bad_val == nums_0[0]);

    fisher_yates(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), std::rand);
    show_data(nums_1, sizeof(nums_1)/sizeof(nums_1[0]));
    
    CHECK( 3 == sizeof(nums_1)/sizeof(nums_1[0]) ); // prepare for test
    bool first  = exactly_one_in_list(nums_1,sizeof(nums_1)/sizeof(nums_1[0]), nums_1[0]);
    bool second = exactly_one_in_list(nums_1,sizeof(nums_1)/sizeof(nums_1[0]), nums_1[1]);
    bool third  = exactly_one_in_list(nums_1,sizeof(nums_1)/sizeof(nums_1[0]), nums_1[2]);
    bool three_tests = first || second || third;
    CHECK( three_tests == true );
  };

};
  