#include <bits/stdc++.h>
using namespace std;
int a[3000];
int main()
{
    int n, m, s = 0, mins = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - m + 1; ++i)
    {
        if (i == 0)
            for (int k = 0; k < m; ++k)
                s += a[k];
        else
            s += a[i + m - 1] - a[i - 1];
        mins = min(s, mins);
    }
    cout << mins;
}
