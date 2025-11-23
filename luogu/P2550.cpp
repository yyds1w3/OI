#include <iostream>
using namespace std;
int main()
{
    int n, a[1001][8] = {0}, b[8] = {0};
    cin >> n;
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < 7; ++j)
            cin >> a[i][j];
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < 7; ++j)
            for (int k = 0; k < 7; ++k)
                if (a[i][j] == a[0][k])
                    a[i][7] += 1;
        b[7 - a[i][7]] += 1;
    }
    for (int i = 0; i < 7; ++i)
    {
        cout << b[i] << " ";
    }
}