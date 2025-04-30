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

void transferNft(unique_ptr<NfToken> & to, unique_ptr<NfToken> & from) {
    to = move(from);
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

    transferNft(otherNft, myNft);
    //otherNft = std::move(myNft);
    cout << otherNft.get()->getName() << endl;
    cout << myNft.get()->getName() << endl;

    string nftName;
    for (int i=0; i < totalNfts; i++) {
        cout << "Enter the name for this NFT: ";
        cin >> nftName;

        unique_ptr<NfToken> myUniqueToken (new NfToken(nftName));
        sha256Hash.compHash(nftName);
        
        myUniqueToken.get()->setHash(sha256Hash.getHash().c_str());
        wallet1.push_back(move(myUniqueToken));
    }

    for (auto it = wallet1.begin(); it != wallet1.end(); it++) {
        cout << it->get()->getHash() << endl;
    }
    
    

    return 0;
}
