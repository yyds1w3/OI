#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double sum;
    cin >> n;
    if (n < 150)
    {
        sum = n * 0.4463;
    }
    else if (n >= 150 && n < 401)
    {
        sum = 150 * 0.4463 + (n - 150) * 0.4663;
    }
    else
    {
        sum = 150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663;
    }
    cout << setprecision(1) << fixed << sum;
}