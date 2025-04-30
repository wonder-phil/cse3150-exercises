#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <openssl/sha.h>

#include "NfToken.h"
#include "ShaMessageDigestHash.h"

using namespace std;



ostream & operator<<(ostream & os, const NfToken & nft) {
    os  << nft.getName()
        << " "
        << nft.getHash();

    return os;
}

void transferExample(unique_ptr<NfToken> & to, unique_ptr<NfToken> & from) {
    to = move(from);
    from.release();
}

int main() {
    int totalNfts = 0;

    ShaMessageDigestHash sha256Hash;
    vector<unique_ptr<NfToken>> wallet1;
    vector<unique_ptr<NfToken>> wallet2;

    cout << "How many NFTs? ";
    cin >> totalNfts;
    cout << endl;

    string nftName;
    cout << "loading into wallet 1" << endl;

    for (int i=0; i < totalNfts; i++) {
        cout << "Enter the name for this NFT: ";
        cin >> nftName;

        sha256Hash.compHash(nftName);
        unique_ptr<NfToken> myNewNft(new NfToken(nftName));
        myNewNft.get()->setHash(sha256Hash.getHash().c_str());
        wallet1.push_back(move(myNewNft));
    }

    for (int i=0; i < totalNfts; i++) {
        cout << * wallet1[i].get() << endl;
        if ("one" == wallet1[i].get()->getName()) {
            unique_ptr<NfToken> temp(new NfToken("temp"));
            transferExample(temp, wallet1[i]);
            wallet2.push_back(move(temp));
        }
    }

    for (int i = 0; i < wallet2.size(); i++) {
        cout << * wallet2[i].get() << endl;
    }

    return 0;
}
