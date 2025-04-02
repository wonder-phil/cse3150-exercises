#include <iostream>
#include <vector>
#include <string>

using namespace std;

auto dividesLambda = [](int n, int d) -> bool {
    return (0 == n % d);
};

int main() {

    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string  myDivisor;
    
    cout << "Enter a divisor" << endl;
    cin >> myDivisor;

    int divisor = stoi(myDivisor);

    for (auto n : numbers ) {
        if (dividesLambda(n, divisor)) {
            cout << divisor << " divides " << n << endl;
        } 
    }

    return 0;
}