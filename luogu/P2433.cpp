#include <bits/stdc++.h>
using namespace std;
constexpr double pi = 3.141593;
int main()
{
    int a;
    cin >> a;
    switch (a)
    {
    case 1:
        cout << "I love Luogu";
        break;
    case 2:
        cout << 6 << " " << 4;
        break;
    case 3:
        cout << 3 << endl << 12 << endl << 2 << endl;
        break;
    case 4:
        cout << setprecision(3) << fixed << 500 / 3.0 << endl;
        break;
    case 5:
        cout << 480 / 32;
        break;
    case 6:
        cout << sqrt(36 + 81);
        break;
    case 7:
        cout << 110 << endl
             << 90 << endl
             << 0 << endl;
        break;
    case 8:
        cout << 10 * pi << endl
             << pi * 5 *5  << endl
             << 4 / 3.0 * pi * 5 * 5 * 5 << endl;
        break;
    case 9:
        cout << 22;
        break;
    case 10:
        cout << 9;
        break;
    case 11:
        cout << 34;
        break;
    case 12:
        cout << int('M' - 'A' + 1) << endl
             << char('A' + 17) << endl;
        break;
    case 13:
        cout << int(pow(4 / 3.0 * pi * (pow(4, 3) + pow(10, 3)), 1 / 3.0));
        break;
    case 14:
        cout << 40;
        break;
    default:
        break;
    }
}