#include <bits/stdc++.h>
using namespace std;
int a[10005][105];
int main()
{
    int n, m, t;
    long long s = 1;
    a[0][0] = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= 100; ++j){
            if (j == 0) a[i][j] = 1;
            else{
                a[i][j] = a[i-1][j] + a[i-1][j-1] % 10007;
            }
        }
    }

    for (int i = 1; i <= m; ++i){
        cin >> t;
        if (t > n){
            s = 0;
            break;
        }    
        s *= a[n][t];
        s %= 10007;
        if (s < 0) s += 10007;
        n -= t;
    }

    cout << s;
}