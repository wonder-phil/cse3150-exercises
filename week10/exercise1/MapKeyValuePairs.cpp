#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> keyValuePairs;

    keyValuePairs["Alice"] = 30;
    keyValuePairs["Bob"] = 25;
    keyValuePairs["Charlie"] = 35;

    cout << "Bob is " << keyValuePairs["Bob"] << " years old." << endl;

    for (const auto & pair : keyValuePairs) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
