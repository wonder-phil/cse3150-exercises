#ifndef _FISHER_YATES_Top_Down_H
#define _FISHER_YATES_Top_Down_H

void swap(int* x, int* y);
void fisher_yates_top_down(int array[], const int length, int (* random_fcn)() );
void show_data(int array[], const int length);

#endif