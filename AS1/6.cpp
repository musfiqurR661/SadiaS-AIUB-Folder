#include <iostream>

using namespace std;

int main() {
    int number;

    cout << "Enter an integer number: ";
    cin >> number;

    if ((number % 2 == 0) && (number % 5 == 0) && (number % 11 == 0)) {
        cout << "The number is divisible by 2, 5, and 11." << endl;
    } else {
        cout << "The number is not divisible by 2, 5, and 11." << endl;
    }

    return 0;
}
