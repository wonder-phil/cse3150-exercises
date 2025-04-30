#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include "readOneLine.h"

int main() {

    using namespace std;

    ifstream in_file;
    in_file.open("the-verdict.txt");

    vector<string> my_vector;

    while (! in_file.eof() ) {

        my_vector = strings_read_one_line(in_file);


        for (auto v : my_vector) {
            cout << v << " ";
        }
        cout << endl;
    }

    in_file.close();

    return 0;
}