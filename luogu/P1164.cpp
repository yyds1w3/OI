#include <iostream>
using namespace std;
int dp[10001];
int v[10001];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i){ // 遍历每一道菜
        for (int j = m; j >= v[i]; --j){ // 允许价格为m ~ v[i], 倒序遍历防止dp被该行更改
            dp[j] += dp[j-v[i]];
        }
    }
    cout << dp[m] << endl;
    return 0;
}