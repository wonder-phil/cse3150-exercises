#ifndef _PERMUTATION_H
#define _PERMUTATION_H


struct Permutation {
    inline static int value = 0;
    enum Direction { INCREMENT, DECREMENT };
    inline static Direction direction = INCREMENT;

    void setDirection(Direction myDirection) {
        direction = myDirection;
    }

    void setValue(int myValue) {
        value = myValue;
    }

    static int getNext() {
        int newValue = value;
        switch(direction) {
            case INCREMENT:
                value++;
                return newValue;
            case DECREMENT:
                value--;
                return newValue;
        }
        return value;
    }

};




#endif
