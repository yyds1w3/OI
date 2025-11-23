#include <bits/stdc++.h>
using namespace std;
int a[21][21] = {0};
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; ++i)
    {
        if (i == 1){
            a[1][1] = 1;
            continue;
        }
        for (int k = 1; k <= i / 2 + 1; ++k)
        {
            a[i][k] = a[i - 1][k - 1] + a[i - 1][k];
        }
        for (int l = i / 2 + 2; l <= i; ++l)
        {
            int m = i - l + 1;
            a[i][l] = a[i][m];
        }
    }

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < i + 1; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}