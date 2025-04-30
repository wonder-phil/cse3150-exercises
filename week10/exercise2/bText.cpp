#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "hello  sellho hell hello hello-there 1 hello2";
    std::regex word_boundary(R"(\b[helo]+\b)");

    std::sregex_iterator begin(text.begin(), text.end(), word_boundary);
    std::sregex_iterator end;

    for (auto it = begin; it != end; ++it) {
        std::cout << "Match: " << it->str() << '\n';
    }
}
