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


int main() {
    int totalNfts = 0;

    ShaMessageDigestHash sha256Hash;

    cout << "How many NFTs? ";
    cin >> totalNfts;
    cout << endl;

    auto arrayOfNfts = make_unique<NfToken[]>(totalNfts);

    vector<unique_ptr<NfToken>> wallet1;
    vector<unique_ptr<NfToken>> wallet2;

    cout << arrayOfNfts[0] << endl;

    unique_ptr<NfToken> myNft (new NfToken("New Token")), otherNft(new NfToken("Bleeble"));

    otherNft = std::move(myNft);


    string nftName;
    for (int i=0; i < totalNfts; i++) {
        cout << "Enter the name for this NFT: ";
        cin >> nftName;

        sha256Hash.compHash(nftName);
        arrayOfNfts[i].setHash(sha256Hash.getHash().c_str());
    }

    for (int i=0; i < totalNfts; i++) {
        cout << arrayOfNfts[i] << endl;
    }
    

    return 0;
}
