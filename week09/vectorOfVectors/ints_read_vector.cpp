#include <istream>
#include <sstream>
#include <vector>

//#include "ints_read_vector.h"

using namespace std;


vector<int> ints_read_vector(istream & in_stream) {
    vector<int> res;
    for(int i; in_stream >> i; ) {
        res.push_back(i);
    }

    return res;
}


vector<int> ints_read_one_line(istream & in_stream) {
    vector<int> res;
    string line;
    
    getline(in_stream, line);
    istringstream is(line);
    string next;
    while (is >> next) {
        res.push_back(stoi(next));
    }

    return res;
}


