#include <iostream>
#include "prefixSum.h"

int prefix_sum(int array[], int last) { /* last must be less than length of the array */
  int sum = 0;
  for (int i=0; i < last; i++) {
    sum += array[i];
  }
  return sum;
}

bool non_negative_prefix_sum(int array[], int length) {
  bool is_non_negative = true;
  for (int i = 0; i < length; i++) {
    int sum = prefix_sum(array,i);
    if (sum >= 1) {
      is_non_negative = false;
      break;
    }
  }
  return is_non_negtive;
}