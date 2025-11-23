#include <bits/stdc++.h>
using namespace std;
int a[102][102] = {0};
int main()
{
    int n, m, k, x_h, y_h, x_s, y_s, sum = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        cin >> x_h >> y_h;
        x_h++, y_h++;
        a[x_h][y_h] = 1;
        a[x_h][y_h - 1] = 1;
        a[x_h][y_h - 2] = 1;
        a[x_h][y_h + 1] = 1;
        a[x_h][y_h + 2] = 1;
        a[x_h - 1][y_h] = 1;
        a[x_h - 2][y_h] = 1;
        a[x_h + 1][y_h] = 1;
        a[x_h + 2][y_h] = 1;
        a[x_h - 1][y_h + 1] = 1;
        a[x_h - 1][y_h - 1] = 1;
        a[x_h + 1][y_h + 1] = 1;
        a[x_h + 1][y_h - 1] = 1;
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> x_s >> y_s;
        x_s++, y_s++;
        for (int i = x_s - 2; i <= x_s + 2; ++i)
        {
            for (int j = y_s - 2; j <= y_s + 2; ++j)
            {
                a[i][j] = 1;
            }
        }
    }

    for (int i = 2; i <= n + 1; ++i)
    {
        for (int j = 2; j <= n + 1; ++j)
        {
            if (a[i][j] == 0)
                sum++;
        }
    }
    cout << sum;
}