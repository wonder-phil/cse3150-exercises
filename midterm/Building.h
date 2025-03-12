#ifndef _BUILDING_H
#define _BUILDING_H

#include <string>

using namespace std;

#define FOUNDATION_SIZE 10

struct Building {
  
    Building();
    ~Building();
    Building(const Building & bldg);

    void set_vals(int i);
    void print_vals();

    private:
        int * foundation = nullptr;
        int count = 0;

};


#endif