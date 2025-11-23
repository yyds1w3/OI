#include <iostream>
using namespace std;
int main()
{
    int n, a[1001][3];
    cin >> n;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
    }
    int ans = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        for (int k = 1; i + k < n + 1; ++k)
        {
            int diff = 0;
            bool cond1 = true;
            for (int j = 0; j < 3; j++)
            {
            if (!(a[i][j] - a[i + k][j] >= -5 && a[i][j] - a[i + k][j] <= 5))
                cond1 = false;
            diff += a[i][j] - a[i + k][j];
            }
            if (cond1 && (diff >= -10 && diff <= 10))
                ans += 1;
        }

    }
    cout << ans;
}