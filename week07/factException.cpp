#include <iostream>
#include <string>

using namespace std;

int fact(int n) {
    if (0 == n)
        return 1;
    else if (4 == n)
        throw string("help a 4!");
    else 
       return n*fact(n-1);
}

/*
    catch(...)...
*/

void other_function() {
    cout << "in other_function" << endl;
     try{ 
        fact(10);
    } catch (int s) {
        cout << "in Other_function: " << s << endl;
    } catch(...) {
        cout << "in Other_function: - ANY remaining type caught" << endl;
        throw string("yipes");
    }
    cout << "out other_function" << endl;
}


int main() {

    cout << "before other_function" << endl;
    
    try {
        other_function();
    } catch(string & s) {
        cout << s << '\n';
    }
    
    

    cout << "after other_function" << endl;

    return 0;
}