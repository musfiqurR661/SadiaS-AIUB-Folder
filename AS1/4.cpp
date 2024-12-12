#include <iostream>

using namespace std;

int main() {
    int Z;

    
    cout << "Enter the value of Z: ";
    cin >> Z;

    
    long long result = 1; 

    //  Z^5
    for (int i = 0; i < 5; i++) {
        result *= Z;
    }

    //  Z^7
    for (int i = 0; i < 2; i++) {
        result *= Z;
    }

    // Z^9
    for (int i = 0; i < 2; i++) {
        result *= Z;
    }

    //  Z^4
    for (int i = 0; i < 4; i++) {
        result *= Z;
    }

    //  Z^3 * Z^2
    for (int i = 0; i < 5; i++) {
        result *= Z;
    }

    // Subtract Z^3 * Z^2 from the previous result
    result -= 1;

   
    cout << "Result: " << result << endl;

    return 0;
}
