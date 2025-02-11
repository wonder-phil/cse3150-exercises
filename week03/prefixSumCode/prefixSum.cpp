#include <iostream>
#include "prefixSum.h"


bool non_negative_prefix_sum(int array[], int length) {
  bool is_non_negative = true;
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i] ;
    if (sum <= -1) {
      is_non_negative = false;
      break;
    }
  }
  return is_non_negative;
}


bool non_positive_prefix_sum(int array[], int length) {
  bool is_non_positive = true;
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i];
    if (sum >= 1) {
      is_non_positive = false;
      break;
    }
  }
  return is_non_positive;
}