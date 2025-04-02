#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

    vector<int> numbers = {1, 2, 3, 4, 5};
    int sum = 0;

    for_each(numbers.begin(), numbers.end(), 
        [&sum](int n) {
        sum += n;
        }
    );

    cout << "Sum: " << sum << endl;
    return 0;
}
