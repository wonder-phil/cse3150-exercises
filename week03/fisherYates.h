#ifndef _FISHER_YATES_H
#define _FISHER_YATES_H

void swap(int* x, int* y);
void fisher_yates(int array[], const int length, int (* random_fcn)() );
void show_data(int array[], const int length);

#endif