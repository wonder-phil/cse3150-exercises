#include <cassert>
#include <iostream>
#include <set>
 
int main()
{
    std::set<int> mySet;
 
    auto result_1 = mySet.insert(3);
    assert(result_1.first != mySet.end()); // it is a valid iterator
    assert(*result_1.first == 3);
    if (result_1.second)
        std::cout << "insert done\n";
 
    auto result_2 = mySet.insert(3);
    assert(result_2.first == result_1.first); // same iterator
    assert(*result_2.first == 3);
    if (!result_2.second)
        std::cout << "no insertion\n";
}