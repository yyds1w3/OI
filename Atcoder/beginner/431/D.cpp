#include <iostream>
#include <queue>
using namespace std;
#define offset 250000
long long dp[2][2 * offset + 1]; // 1M
int main()
{
    int N, w, h, b = 0;
    long long ans = 0, t;
    cin >> N;
    int l = offset, r = offset;
    dp[0][offset] = 1;
    for (int i = 1; i <= N; ++i)
    {
        cin >> w >> h >> b;
        l -= w;
        r += w;

        for (int j = l; j <= r; ++j)
        {
            if (dp[0][j + w] != 0){
                dp[1][j] = max(dp[0][j + w] + h, dp[1][j]);
            }
            if (dp[0][j - w] != 0){
                dp[1][j] = max(dp[0][j - w] + b, dp[1][j]);
            }
        }
        for (int j = l; j <= r; ++j)
        {
            dp[0][j] = dp[1][j];
        }

        if (i == N)
        {
            for (int j = offset; j <= 2 * offset + 1; ++j)
            {
                ans = max(ans, dp[1][j]);
            }
        }
    }
    cout << --ans;
}