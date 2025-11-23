#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, sum = 0;
    cin >> n;
    int Max = 0, Min = 11;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        Max = max(Max, x);
        Min = min(Min, x);
        sum += x;
    }
    cout << setprecision(2) << fixed << (sum - Max - Min) / double(n - 2);
}