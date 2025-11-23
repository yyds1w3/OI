#include <bits/stdc++.h>
using namespace std;
int a[20][20] = {0};
int main()
{
    int n, value = 2;
    cin >> n;
    int i = 1, j = 1;
    a[1][1] = 1;
    while (value < n * n + 1)
    {
        while (j + 1 <= n && a[i][j + 1] == 0)
        {
            j++;
            a[i][j] = value;
            value++;
        }
        while (i + 1 <= n && a[i+1][j] == 0)
        {
            i++;
            a[i][j] = value;
            value++;
        }
        while (j - 1 >= 1 && a[i][j - 1] == 0)
        {
            j--;
            a[i][j] = value;
            value++;
        }
        while (i - 1 >= 1 && a[i-1][j] == 0)
        {
            i--;
            a[i][j] = value;
            value++;
        }

    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            printf("%3d", a[i][j]);
        }
        cout << endl;
    }
}