#include <iostream>
#include <random>
#include <vector>
#include <utility>  // for std::move()

#include "AiBot.h"

using namespace std;


int main()
{
  // Short String Optimizer - will put this long string on the heap
  AiBot aiBot{"Wolfgang Amadeus Mozart" };
  for (int val : {0, 8, 15}) {
    aiBot.addValue(val);
  }
  std::cout << "aiBot: " << aiBot << '\n';    // print value of initialized c

  // insert the AiBot twice into a collection of AiBots:
  std::vector<AiBot> aiBots;
  aiBots.push_back(aiBot);             // copy into the vector
  aiBots.push_back(std::move(aiBot));  // move into the vector
  std::cout << "This aiBot was MOVED: <" << aiBot << ">" << endl;    

  // print all AiBots in the collection:
  std::cout << "AiBots:\n";
  for (const AiBot & aiBot : aiBots) {
    std::cout << "  " << aiBot << '\n';
  }
}