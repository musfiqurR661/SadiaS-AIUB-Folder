#include <iostream>
using namespace std;
int main()
{
    float a, b, c, d, e;

    cin >> a >> b >> c >> d >> e;

    float sum = a + b + c + d + e;
    float avg = sum / 5;

     cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;

    int avgInInteger = static_cast<int>(avg);

    if (avgInInteger % 2 == 0)
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "odd" << endl;
    }

    return 0;
}
