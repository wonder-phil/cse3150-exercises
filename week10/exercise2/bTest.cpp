#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "hello hell hello hello-there 1 hello2 shell";
    std::regex word_boundary(R"(\bhello\b)");

    std::sregex_iterator begin(text.begin(), text.end(), word_boundary);
    std::sregex_iterator end;

    for (auto it = begin; it != end; ++it) {
        std::cout << "Match: " << it->str() << '\n';
    }
}
