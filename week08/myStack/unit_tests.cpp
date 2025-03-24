#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "stack_1.h"


TEST_CASE("Stack tester") {
    
    SUBCASE("size checking") {

        const int my_stack_size_Zero = 0;
        stack<int> s0 = get_stack(my_stack_size_Zero);
        CHECK(s0.size() == my_stack_size_Zero);

        const int my_stack_size = 6;
        stack<int> s1 = get_stack(my_stack_size);
        CHECK(s1.size() == my_stack_size);

        const int my_stack_size_node = 5;
        stack<node> s2 = get_stack_node(my_stack_size_node);
        CHECK(s2.size() == my_stack_size_node);

        node test = s2.top();
        string top_name = test.name;
        int top_number = test.number;
        CHECK(top_name == "Ada Lovelace");
        CHECK(top_number == 4);

    };

    SUBCASE("stack copying") {

        const int my_stack_size = 6;
        stack<int> s = get_stack(my_stack_size);
        stack<int> t = s;
        CHECK(s == t);

        s.push(99);

        CHECK_FALSE(s.size() == t.size());
        CHECK_FALSE(s == t); // different data structures (stacks)

    }



};