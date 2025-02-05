/*
  from https://en.cppreference.com/
*/
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
 
int main()
{
    // use current time as seed for random generator
    std::srand(std::time(NULL));
 
    std::cout << "RAND_MAX: " << RAND_MAX << '\n'
              << "INT_MAX: " << INT_MAX << '\n'
              << "Random value on [0,1]: "
              << static_cast<double>(std::rand()) / RAND_MAX << '\n';
}