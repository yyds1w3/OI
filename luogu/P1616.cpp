#include <iostream>
#include <ios>
using namespace std;
int t[10005], v[10005];
long long dp[10000005];
int main(){
    int T, M;
    long long ans = 0;
    cin >> T >> M;
    for (int i = 1; i <= M; ++i){
        cin >> t[i] >> v[i];
    }
 
    for (int i = 1; i <= M; ++i){
        for (int j = 1; j <= T; ++j){
            if (j - t[i] >= 0){
                dp[j] = max<long long>(dp[j-t[i]] + v[i], dp[j]);
                ans = max<long long>(ans, dp[j]);
            }
        }
    }
    cout << ans;
}