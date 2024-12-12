#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number: ";
    float n;
    cin >> n;

    int integerPart = static_cast<int>(n);  // Casting to int to get the integer part

    if (n == static_cast<float>(integerPart)) {
        cout << "The entered number is an integer." << endl;
    } else {
        cout << "The entered number is a float." << endl;
    }

    return 0;
}
