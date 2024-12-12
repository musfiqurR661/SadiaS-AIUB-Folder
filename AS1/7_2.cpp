#include <iostream>

using namespace std;

int main() {
    char gender;

    // Input the gender character
    cout << "Enter Gender: ";
    cin >> gender;

    switch (gender) {
        case 'M':
        case 'm':
            cout << "Gender is Male" << endl;
            break;
        case 'F':
        case 'f':
            cout << "Gender is Female" << endl;
            break;
        default:
            cout << "Undefined" << endl;
    }

    return 0;
}
