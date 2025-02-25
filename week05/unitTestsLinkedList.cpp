#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include <iostream>
#include "./include/doctest.h"
#include "LinkedList.h"

using namespace std;



TEST_CASE("Linked List Insertion Edge Cases") {

  SUBCASE("empty and almost-empty linked lists") {
  
    LinkedList ll_0, ll_start, ll_end;

    ll_start.insertAtBeginning(5);
    ll_end.insertAtEnd(-55);

    CHECK( 0 == ll_0.getSize() );
    CHECK( 1 == ll_start.getSize() );
    CHECK( 1 == ll_end.getSize() );
               
  };

  SUBCASE("insertion and deletion") {
    

    LinkedList ll_0, ll_1;

    ll_0.insertAtBeginning(2);
    ll_0.insertAtEnd(3);
    ll_0.insertAtBeginning(1);

    CHECK( 1 == ll_0.getValueAt( 1 ) );
    CHECK( 2 == ll_0.getValueAt( 2 ) );
    CHECK( 3 == ll_0.getValueAt( 3 ) );
    
  };

};

