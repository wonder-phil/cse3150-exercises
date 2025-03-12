#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "MyWStack.h"


TEST_CASE("Stack tester") {
    
    SUBCASE("size checking") {

        MyWStack<int, 10> s0;
        CHECK(0 == s0.size());

        int neg5 = -5;
        MyWStack<int, 10> s1;
        s1.push(neg5);
        CHECK(1 == s1.size());

        CHECK(neg5 == s1.top());

        int neg10 = -5;
        
        s1.push(neg10);
        CHECK(2 == s1.size());

        CHECK(neg10 == s1.top());

        s1.pop();
        CHECK(1 == s1.size());
        CHECK(neg5 == s1.top());

    };

    SUBCASE("stack copying") {

        

    }



};