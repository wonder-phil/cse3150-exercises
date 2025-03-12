#include <iostream>


using namespace std;


class Building {

    friend ostream & operator<<(ostream & os, const Building & building);

    int * intArray;
    int size;
    static int numberOfCopies;

    public:
        Building() : size{0} {}

        Building(int mySize) : size{mySize} {
            if (0 == numberOfCopies) {
                cout << "HERE " << size << endl;
                intArray = new int[size];
                for (int i=0; i < size; i++) {
                    intArray[i] = 0;
                }
                numberOfCopies = 1;
            } 
        }

        Building(const Building & building) : size{building.size}, intArray{building.intArray} {
            numberOfCopies++;
            for (int i=0; i < size; i++) {
                intArray[i] += 1;
            }
        }

        ~Building() {
            if (numberOfCopies > 0) {
                delete [] intArray;
                numberOfCopies = 0;
            }
        }
};

int Building::numberOfCopies = 0;


ostream & operator<<(ostream & os, const Building & building) {
    if (0 == Building::numberOfCopies) {
        os << "Empty array \n" ;
    } else {
        for (int i =0; i < building.size; i++) {
            os << building.intArray[i] << " ";
        }
        os << "\n" ;
    }
    return os;
}


int main() {

    Building bldg(10);

    Building b0(3), b1(3), b2(3);

    b0 = bldg;
    cout << "b0: " << b0 << endl;

    b1 = bldg;
    cout << "b1: " << b1 << endl;

    b2 = b1;
    cout << "b2: " << b2 << endl;

    return 0;
}
