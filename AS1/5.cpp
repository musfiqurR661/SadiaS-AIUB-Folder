#include <iostream>

using namespace std;

int main() {
    double Base, Height;

    cout << "Enter the base of the triangle: ";
    cin >> Base;

    cout << "Enter the height of the triangle: ";
    cin >> Height;

    double area = 0.5 * Base * Height;

    if (static_cast<int>(area) % 2 == 0) {
        cout << "The area of the triangle is even: " << area << endl;
    } else {
        cout << "The area of the triangle is odd: " << area << endl;
    }

    return 0;
}
