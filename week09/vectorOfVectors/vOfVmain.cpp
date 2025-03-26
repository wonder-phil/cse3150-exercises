#include <iostream>
#include <vector>
#include <fstream>
#include <istream>

//#include "ints_read_vector.cpp"
#include "ints_read_matrix.cpp"



using namespace std;

ostream & operator<<(ostream & os, const vector<int> & vector) {
    for (auto v: vector) {
        os << v << " ";
    }
    os << "\n";
    return os;
}


ostream & operator<<(ostream & os, const vector<vector<int>> & vv) {
    for (auto v: vv) {
        os << v;
    }
    os << "\n";
    return os;
}

int main() {

    ifstream myFile;
    myFile.open("basicMatrix.txt");

    vector<vector<int>> myMatrix = ints_read_matrix(myFile);

    cout << myMatrix[0][0] << endl;

    cout << "-------------" << endl;
    cout << myMatrix << endl;
    cout << "-------------" << endl;

    myFile.close();


    return 0;
}