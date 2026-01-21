#ifndef __ISPRIMEFUNCTION_H
#define __ISPRIMEFUNCTION_H

bool isPrimeInteger(int pTest) {
    bool isPrime = true;

    for (int i = 2; i < pTest; i++) {
        if (pTest % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

#endif
