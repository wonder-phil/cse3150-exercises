#ifndef _UNIGRAM_H
#define _UNIGRAM_H

#include <string>


struct Unigram {
    std::string token;
    int id;

    bool operator<(Unigram & right) {
        return token < right.token;
    }

    Unigram(string _token, int _id) : token(_token), id(_id) {}
};

struct UnigramCompare {
    bool operator()(const Unigram & left, const Unigram & right) {
        return left.token < right.token;
    }  
};

ostream & operator<<(ostream & os, const Unigram & unigram) {
    os << unigram.token 
       << ": "
       << unigram.id
       << " ";

       return os;
}
#endif
