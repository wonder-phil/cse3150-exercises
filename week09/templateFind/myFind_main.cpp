#include <iostream>
#include <vector>

#include "myFind.h"

int main() {

    std::vector<int> x = {1,5,8,11,25,30,32,47,78,99,101};

    bool foundIt = myfind(x,33);

    std::cout << "Found it? " << (foundIt ? "True" : "False ") << std::endl;

    return 0;
}