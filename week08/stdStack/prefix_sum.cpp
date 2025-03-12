#include "prefix_sum.h"

int prefix_sum(int array[], int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i];
  }
  
  return sum;
}

bool non_negative_prefix_sum(int array[], int length) {
  bool result = true;
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i];
    if (sum <= -1) {
      result = false;
      break;
    }
  }
  
  return result;
}

bool non_positive_prefix_sum(int array[], int length) {
  bool result = true;
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i];
    if (sum >= 1) {
      result = false;
      break;
    }
  }
  
  return result;
}