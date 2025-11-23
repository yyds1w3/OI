#include <bits/stdc++.h>
using namespace std;
#define f(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, maxn = 0, maxi = 0;
    cin >> n;
    string a[1001];
    int b[1001][4] = {0};
    f(i,n){
        cin >> a[i] >> b[i][1] >> b[i][2] >> b[i][3];
        b[i][0] = b[i][1] + b[i][2] + b[i][3];
        if (b[i][0] > maxn)
            maxi = i;
        maxn = max(maxn, b[i][0]);
    }
    cout << a[maxi] << " " << b[maxi][1] << " " << b[maxi][2] << " " << b[maxi][3];
}