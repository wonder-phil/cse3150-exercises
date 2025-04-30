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
        << ": "
        << nft.getHash();

    return os;
}


void transferNft(unique_ptr<NfToken> & to, unique_ptr<NfToken> & from) {
    to = move(from);
    from.release();
}

/*
 *
    transfer unique_ptr from fromVector at iteration position pos
    into the toVector

 *
 */
void transferNftVector(vector<unique_ptr<NfToken>> & toVector, vector<unique_ptr<NfToken>> & fromVector, 
    vector<unique_ptr<NfToken>>::iterator pos) {

    toVector.push_back(move(*pos)); 

    (*pos).release();
    fromVector.erase(pos);
}

int main() {
    int totalNfts = 0;

    unique_ptr<NfToken> myNft (new NfToken("New rocket NF Token")), otherNft(new NfToken("Blue origin rocket token"));

    otherNft = std::move(myNft); // myNft; Ouch!

    cout << "Not minted but has a name: <" << otherNft.get()->getName() << "> at address :" << otherNft.get() << endl;


    ShaMessageDigestHash sha256Hash;

    cout << "How many NFTs? ";
    cin >> totalNfts;
    cout << endl;

    vector<unique_ptr<NfToken>> wallet1;
    vector<unique_ptr<NfToken>> wallet2;

    cout << "Wallet 1" << endl;
    string nftName;
    for (int i=0; i < totalNfts; i++) {
        cout << "Enter the name for this NFT: ";
        cin >> nftName;

        sha256Hash.compHash(nftName);
        unique_ptr<NfToken> myNft(new NfToken(nftName));
        myNft.get()->setHash(sha256Hash.getHash().c_str());
        wallet1.push_back(move(myNft));
    }

    cout << "Wallet 2" << endl;
    for (int i=0; i < totalNfts; i++) {
        cout << "Enter the name for this NFT: ";
        cin >> nftName;

        sha256Hash.compHash(nftName);
        unique_ptr<NfToken> myNft(new NfToken(nftName));
        myNft.get()->setHash(sha256Hash.getHash().c_str());
        wallet2.push_back(move(myNft));
    }

    //transferNft(wallet2[0], wallet1[0]);

    transferNftVector(wallet2, wallet1, wallet1.begin());
    

    cout << "Wallet 1" << endl;
    for (int i=0; i < wallet1.size(); i++) {
        cout << * wallet1[i].get() << endl;
    }

    cout << "Wallet 2" << endl;
    for (int i=0; i < wallet2.size(); i++) {
        cout << * wallet2[i].get() << endl;
    }


    
    
    

    return 0;
}