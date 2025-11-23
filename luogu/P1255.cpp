#include <iostream>
#include <cstring>
using namespace std;
long long dp[5001];
int main(){
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i){
        dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[n];
}