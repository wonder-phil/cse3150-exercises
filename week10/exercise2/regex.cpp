#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string input = "Hello, world! This is0 is1 is, is! is? C++: regex_test.";
    regex word_regex{"\\b\\w+\\b"};

    auto words_begin = sregex_iterator(input.begin(), input.end(), word_regex);
    auto words_end = sregex_iterator();

    cout << "Words found:\n";
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        cout << i->str() << endl;
    }

    return 0;
}

