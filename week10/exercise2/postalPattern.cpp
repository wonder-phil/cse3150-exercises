#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string input = "CT 06902-1234";
    regex word_regex{"(\\w{2}\\s*\\d{5}(-\\d{4})?)"};

    auto words_begin = sregex_iterator(input.begin(), input.end(), word_regex);
    auto words_end = sregex_iterator();

    cout << "Words found:\n";
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        cout << i->str() << endl;
    }

    return 0;
}