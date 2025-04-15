#ifndef _TOKEN_H
#define _TOKEN_H

#include <iostream>
#include <string>
#include <cstring>
#include <openssl/sha.h>

using namespace std;


class NfToken {

    string tokenName;
    string myHash;
     
    public:
        NfToken() {}
        NfToken(string name) : tokenName{name} {}

        void setHash(string inputHash) {
            myHash = inputHash;
        }

        void setName(string name) {
            tokenName = name;
        }

        string getName() const {
            return tokenName;
        }

        string getHash() const {
            return myHash;
        }

};


#endif
