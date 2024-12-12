#include <iostream>

using namespace std;

int main() {
    char gender;

    // Input the gender character
    cout << "Enter Gender: ";
    cin >> gender;

    if (gender == 'M' || gender == 'm') {
        cout << "Gender is Male" << endl;
    } else if (gender == 'F' || gender == 'f') {
        cout << "Gender is Female" << endl;
    } else {
        cout << "Undefined" << endl;
    }

    return 0;
}
