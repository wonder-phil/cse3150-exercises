#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "readin_return_int_stack.h"


TEST_CASE("Stack tester") {
    
    SUBCASE("size checking") {

        stack<int> s0;
        CHECK(0 == s0.size());

        stack<int> s1;
        s1.push(99);
        CHECK(1 == s1.size());

    };

    SUBCASE("stack copying") {

        const int my_stack_size = 6;
        stack<int> s;
        s.push(55);
        stack<int> t = s;
        CHECK(s == t);

        s.push(99);

        CHECK_FALSE(s.size() == t.size());
        CHECK_FALSE(s == t); // different data structures (stacks)

    }



};