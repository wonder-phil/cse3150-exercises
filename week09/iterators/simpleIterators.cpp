#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {9,8,7,6,5,4,3,2,1};

    for (vector<int>::iterator iv = vec.begin(); iv != vec.end(); iv++) {
        cout << *iv << endl;
    }

    cout << "---------------" << endl;

    for (auto iv = vec.begin(); iv != vec.end(); iv++) {
        cout << *iv << endl;
    }

    return 0;
}