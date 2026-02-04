#include <iostream>

#include "PyLongObject.h"

PyLongObject::PyLongObject(long long _iValue) {
        iValue = _iValue;
    }

int PyLongObject::getDigitN(int n) const {  // returns -1 on failure
    if (n > numDigits && !fitsInLongLong) {
        return -1;
    } else {
        return digitsBase30[n];
    }
}

long long PyLongObject::getSmallValue() {
    if (fitsInLongLong) {
        return iValue;
    } else {
        return -1;
    }
}

bool PyLongObject::operator==(const PyLongObject & other) const {
    if (this == &other) {
        return true;
    } else {
        if (fitsInLongLong != other.fitsInLongLong) return false;
        if (fitsInLongLong == other.fitsInLongLong && true == fitsInLongLong) {
            if (iValue == other.iValue) {
                return true;
            } else {
                return false;
            }
        }
        if (fitsInLongLong == other.fitsInLongLong && false == fitsInLongLong) {
            if (numDigits != other.numDigits) {
                return false;
            } else {
                for (int i = 0; i < numDigits; i++) {
                    if (getDigitN(i) != other.getDigitN(i)) {
                        return false;
                    }
                }
            }
        }
    }
}

ostream & operator<<(ostream & os, const PyLongObject & pyLongObject) {
    if (pyLongObject.fitsInLongLong) {
        os << pyLongObject.iValue;
    } else {

    }

    return os;
};
