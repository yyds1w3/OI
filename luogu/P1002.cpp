#include <bits/stdc++.h>
using namespace std;
long long  dp[30];
int  m[30][30];
int main()
{
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 2, y1 += 2, x2 += 2, y2 += 2;
    m[y2][x2] = 1; m[y2-2][x2-1] = 1; m[y2-1][x2-2] = 1;m[y2-2][x2+1] = 1; m[y2-1][x2+2] = 1;
    m[y2+2][x2+1] = 1; m[y2+2][x2-1] = 1; m[y2+1][x2+2] = 1; m[y2+1][x2-2] = 1;
    dp[2] = 1;
    for (int i = 2; i <= y1; ++i){
        for (int j = 2; j <= x1; ++j){
            if (m[i][j] == 1){
                dp[j] = 0;
                continue;
            }
            dp[j] += dp[j-1];
        }
    }
    cout << dp[y1];

}