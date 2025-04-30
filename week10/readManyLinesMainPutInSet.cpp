#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <set>

#include "readOneLine.h"
#include "unigram.h"



int main() {

    using namespace std;

    ifstream in_file;
    in_file.open("the-verdict.txt");

    vector<string> my_vector;
    set<Unigram, UnigramCompare> myUnigrams;
    int idCount = 0;

    while (! in_file.eof() ) {

        my_vector = strings_read_one_line(in_file);

        for (auto v : my_vector) {

            Unigram unigram(v,idCount);

            auto insertResult = myUnigrams.insert(unigram);
            if (insertResult.second) {
                cout << "inserted: " << idCount++ << endl;
            } else {
                cout << "already in the set" << endl;
            }

        }

        //if (idCount > 1000) break;
        cout << endl;
    }

    for (auto iter = myUnigrams.begin(); iter != myUnigrams.end(); iter++) {
        cout << *iter << endl;
    } 

    in_file.close();

    return 0;
}