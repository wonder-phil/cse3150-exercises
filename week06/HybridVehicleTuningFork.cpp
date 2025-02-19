#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
	public:

		string name;

		Vehicle(){}
		Vehicle(string name) {
			cout << "Constructor: Vehicle, name: " << name << endl;
		}
		
		~Vehicle() {
			cout << "destructor: Vehicle" << endl;
		}
};


class Gasoline : public Vehicle {
	public:
		Gasoline(string name) : Vehicle(name) {
			cout << "Constructor: Gasoline, name: " << name << endl;
		}
		~Gasoline() {
			cout << "destructor: Gasoline, name: " << name << endl;
		}
};

class Electric : public Vehicle {
	public:
		Electric(string name) : Vehicle(name) {
			cout << "Constructor: Electric, name: " << name << endl;
		}
		~Electric() {
			cout << "destructor: Electric, name: " << name << endl;
		}
};

class Hybrid : public Electric, public Gasoline {
	public:
		Hybrid(string name) : Electric(name), Gasoline(name) { // Electric("Electron"), Gasoline("Fuel") {
			cout << "Constructor: Hybrid, name: " << name << endl;
		}
		~Hybrid() {
			cout << "Destructor: Hybrid: " << Electric::name << Gasoline::name <<  endl;
		}
};


int main() {
	string whichVehicle = "Super vehicle";
	Hybrid Hybrid(whichVehicle);

    return 0;
}