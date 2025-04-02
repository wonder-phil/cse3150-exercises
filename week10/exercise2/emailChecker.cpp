#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string text = "email1@example.com and 1@2.3 and @x.com how about this: a@b.c";
    regex pattern(R"(\w+@\w+\.\w+)");

    sregex_iterator begin(text.begin(), text.end(), pattern);
    sregex_iterator end;

    for (sregex_iterator i = begin; i != end; ++i) {
        smatch match = *i;
        cout << "Found: " << match.str() << endl;
    }

    return 0;
}
