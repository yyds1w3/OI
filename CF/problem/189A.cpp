#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
const int N = 4001;
int dp[N];
int main(){
    IOS;
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    fill(dp+1, dp+1+n, -0x3f3f3f3f);
    for (int i = 0; i < 3; ++i){
        for (int j = 1; j <= n; ++j){
            if (j >= a[i])
                dp[j] = max(dp[j - a[i]] + 1, dp[j]);
        }
    }
    if (dp[n] < 0) cout << "-1";
    else cout << dp[n];
}