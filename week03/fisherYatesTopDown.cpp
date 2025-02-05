#include <iostream>
#include <random>
#include "fisherYatesTopDown.h"


using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


void show_data(int array[], const int length) {
  for (int i=0; i < length; i++) {
    cout << array[i] << " ";
  }
}
/*
 * lst[] = {5,40}
 * length   i   rnd_location   lst[]
 * ----------------------------------
 * 2        1     0             [40,5]
 *                              [5,40]
 *                              
 *          0
 * 
*/
void fisher_yates_top_down(int array[], const int length, int (* random_fcn)()) {
  for (int i = length -1; i >= 0; i--) {
    int rnd_location = random_fcn() % (i+1);
    swap(& array[i], & array[rnd_location]);
  }
}