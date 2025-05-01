#include <iostream>
#include <unistd.h>

using namespace std;

int main() {

    int seconds{0};
    cin >> seconds;
    cout << seconds << " : seconds" << endl;

    cout << "Starting" << endl;
    sleep(seconds);
    cout << "Done" << endl;

    return 0;
}