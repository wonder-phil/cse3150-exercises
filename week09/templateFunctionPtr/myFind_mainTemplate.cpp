#include <iostream>
#include <vector>

#include "myFindTemplate.cpp"



int main() {

    std::vector<int> myVector = {1,5,8,11,25,30,32,47,78,99,101};

    int x = -99;
    bool foundIt = myfind(myVector, x, lessThan);

    std::cout << "Found it? " << (foundIt ? "True" : "False ") << std::endl;

    return 0;
}