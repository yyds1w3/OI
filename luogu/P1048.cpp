#include <iostream>
#include <ios>
using namespace std;
int t[101], v[101], dp[1001];
int main(){
    int T, M, ans = 0;
    cin >> T >> M;
    for (int i = 1; i <= M; ++i){
        cin >> t[i] >> v[i];
    }
 
    for (int i = 1; i <= M; ++i){
        for (int j = T; j >= 1; --j){
            if (j - t[i] >= 0){
                dp[j] = max<int>(dp[j-t[i]] + v[i], dp[j]);
                ans = max<int>(ans, dp[j]);
            }
        }
    }
    cout << ans;
}