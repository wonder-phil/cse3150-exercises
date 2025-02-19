#include <iostream>


using namespace std;

int main() {

    string * array = new string("hello");
    cout << "array = " << *array << endl;

    array = new string("good day"); 
    cout << "array = " << *array << endl;


    return 0;
}




/*
    valgrind --leak-check=full --show-leak-kinds=all  --track-origins=yes  ./a.out 
    LEAK SUMMARY:
       definitely lost: 64 bytes in 2 blocks
    */