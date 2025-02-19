#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
	protected:
		double weight;
		string name;

	public:
		Vehicle() { cout << "Constructor(): Vehicle" << endl; }
		Vehicle(string name) { cout << "Constructo(string name): Vehicle" << endl; }
		
		~Vehicle() {
			cout << "destructor: Vehicle" << endl;
		}

		virtual void Start() { cout << "Vehicle START"  << endl; }
		virtual void Stop() { cout << "Vehicle STOP"  << endl; }
		
};

class Gasoline : public virtual Vehicle {
	public:
		Gasoline(string name) : Vehicle(name) {
			cout << "Constructor: Gasoline" << endl;
		}
		~Gasoline() {
			cout << "destructor: Gasoline" << endl;
		}

		double gasolineMilesPerDollar() {
			cout << "to Update" << endl;

			return 20.0;
		}

		
};

class Electric : public virtual Vehicle {
	public:
		Electric(string name) : Vehicle(name) {
			cout << "Constructor: Electric" << endl;
		}
		~Electric() {
			cout << "destructor: Electric" << endl;
		}

		double electricMilesPerDollar() {
			cout << "to Update" << endl;

			return 20.0;
		}

};


class Hybrid : public Electric, public Gasoline {

	private:
		double _percentGas;

	public:
		Hybrid(string name) : Electric(name), Gasoline(name) {
			cout << "Constructor: Hybrid" << endl;
		}
		~Hybrid() {
			cout << "destructor: Hybrid" << endl;
		}

		double fuelEffiencyPerDollar() {

			cout << "to Update" << endl;

			double precentGas = PrecentGas();

			return (electricMilesPerDollar() * (1-precentGas) + precentGas*gasolineMilesPerDollar());
		}

		double PrecentGas() {
			return _percentGas;
		}

		void PrecentGas(double pg) {
			_percentGas = pg;
		}

		void Start() override { cout << "Hybrid START"  << endl; }
		void Stop() override { cout << "Hybrid STOP"  << endl; }
};


int main() {
	string whichVehicle = "Super vehicle";
	Hybrid hybrid(whichVehicle);

	hybrid.Start();

	cout << hybrid.fuelEffiencyPerDollar() << endl;

	return 0;
}