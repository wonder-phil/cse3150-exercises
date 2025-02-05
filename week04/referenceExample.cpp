#include <iostream>
#include <string>
using namespace std;

void sumOf(string a, int & ttl) {
 ttl = 0;
 for (int i=0; i < a.size(); i++) {
        ttl += a[i];
    }
    a[0] = 88;
}

int main() {
    string x = { 'h', 'e', 'l', 'l', 'o'};
    int sum;
    sumOf(x,sum);
    cout << "sum = " << sum << endl;
    cout << "x = "   << x << endl;
    return 0;
}
