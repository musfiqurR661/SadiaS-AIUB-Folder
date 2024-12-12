#include <iostream>
using namespace std;
int main()
{
    int Year, rem_4, rem_100, rem_400;
    cout << "Enter a Year" << endl;
    cin >> Year;
    rem_4 = Year % 4;
    rem_100 = Year % 100;
    rem_400 = Year % 400;
    if (Year >= 1800 && Year <= 2023)
    {
        if ((rem_4 == 0 && rem_100 != 0) || (rem_400 == 0))
    {
        cout << Year << " is a leap year" << endl;
    }
    else
    {
        cout << Year << " is not a leap year" << endl;
    }
    }
    else
    {
        cout << "Enter a Valid Year" << endl;
    }
         
    return 0;
}
