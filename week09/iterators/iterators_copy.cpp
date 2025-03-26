#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

template<typename InIterator, typename OutIterator>
void my_copy(InIterator start, InIterator stop, OutIterator into) {

    while (*start != *stop) {
        *into = *start;
        ++into;
        ++start;
    }
}

int main() {
    using namespace std;

    vector<int> v = {1,2,3,4,5};
    vector<int> w ;

    my_copy(v.begin(), v.end(), back_inserter(w));

    for (auto a : w) {
        cout << a << " ";    
    }
    cout << endl;

    return 0;
}