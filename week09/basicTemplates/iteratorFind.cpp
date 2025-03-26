#include <iostream>
#include <vector>

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