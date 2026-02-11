#include <iostream>

#include <cmath>

using namespace std;


int32_t pseudoRamdom(int limit) {
    
    int value = rand() % limit;
    return value;
}


void fisherYates(int *array, int totalElements, int (*randomFcn)(int limit)) {
    for(int i=totalElements -1; i > 0 ; i--) {
        int randomIndex = randomFcn(i);
        int temp = array[i];
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
}

int main() {

    srand(0);
    int n{0};

    cout << "Enter an integer: " ;
    cin >> n;

    int array[2*n];

    for (int i=0 ; i < 2*n ; i++) {
        if (i < n) {
            array[i] = 1;
        } else {
            array[i] = -1;
        }
    }

    fisherYates(array, 2*n, pseudoRamdom);


    for (int i = 0; i < 2*n; i++) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}