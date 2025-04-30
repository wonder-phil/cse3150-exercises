#ifndef _READ_ONE_LINE_
#define _READ_ONE_LINE_


#include <istream>
#include <sstream>
#include <vector>
#include <string>

#include "readOneLine.h"

using namespace std;


vector<string> strings_read_one_line(istream & in_stream) {
    vector<string> res;
    string line;
    
    getline(in_stream, line);
    istringstream is(line);
    string next;
    while (is >> next) {
        res.push_back(next);
    }

    return res;
}


#endif
