#include <iostream>
#include <memory>
#include <string>

using namespace std;


class Animal {
public:
    Animal(const string & name) : _name(name) {
        cout << _name << " is created \n";
    }

    ~Animal() {
        cout << _name << " is destroyed \n";
    }

    void makeNoise() {
        cout << _name << " makes noise !\n";
    }

private:
    string _name;
};


int main() {
    shared_ptr<Animal> animal_1 = make_shared<Animal>("Dog");

    animal_1->makeNoise();

    {
        shared_ptr<Animal> animal_2 = animal_1; // shared ownership
        cout << "animal created, use_count = " << animal_1.use_count() << "\n";

        animal_2->makeNoise();
    } 

    cout << "Back in main, use_count = " << animal_1.use_count() << "\n";
}
