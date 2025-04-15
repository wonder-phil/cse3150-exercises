#ifndef _SHA_MESSAGE_DIGEST_H
#define _SHA_MESSAGE_DIGEST_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/sha.h>

using namespace std;

class ShaMessageDigestHash {

    string myHash;

    string toHexString(const unsigned char * data, size_t len) {
        ostringstream oss;
        for (size_t i = 0; i < len; ++i)
            oss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
        return oss.str();
    }

    public:
        ShaMessageDigestHash() {}

        void compHash(const string & data) {
            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256_CTX sha256;
            SHA256_Init( & sha256);
            SHA256_Update( & sha256, data.c_str(), data.size());
            SHA256_Final(hash, & sha256);

            myHash = toHexString(hash,SHA256_DIGEST_LENGTH);
        }

        string getHash() {
            return myHash;
        }
};

#endif
