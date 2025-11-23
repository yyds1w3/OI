#include <bits/stdc++.h>
using namespace std;

int main()
{
    double s;
    cin >> s;
    for (int i = 1;; ++i)
    {
        if (pow(0.980,  i) <= 1 - 0.01 * s)
        {
            cout << i;
            break;
        }
    }
}