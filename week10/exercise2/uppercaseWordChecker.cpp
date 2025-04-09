#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string text = "ABC abc 1234 Abc eEF X XY";
    regex pattern(R"(\b[A-Z]+\b)");

    sregex_iterator begin(text.begin(), text.end(), pattern);
    sregex_iterator end;

    for (sregex_iterator i = begin; i != end; ++i) {
        smatch match = *i;
        cout << "Found: " << match.str() << endl;
    }

    return 0;
}
