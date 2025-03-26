#include <iostream>
#include <vector>

using namespace std;

template<typename InputIterator, typename T>
InputIterator myInteratorfind(InputIterator from, InputIterator to, const T & v) {

  while (from != to) {
    if (v == *from) {
      return from;
    }
    ++from;
  }
  return from;
}


int main() {
    vector<int> myVector = {9,22,38,8,15,-4,11,481,2};

    auto iterReturn = myInteratorfind(myVector.begin(), myVector.end(), 2);

    if (myVector.end() == iterReturn) {
        cout << "Not found" << endl;
    } else {
        cout << "Found: " << *iterReturn << endl;
    }

    return 0;
}