#include <bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 2; i < n; ++i)
    {
        for (int j = 0; j < i - 1; ++j)
        {
            for (int k = j + 1; k < i; ++k)
            {
                if (a[j] + a[k] == a[i])
                {
                    ans++;
                    j = i - 2;
                    break;
                }
                else if (a[j] + a[k] > a[i])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    cout << ans;
}
