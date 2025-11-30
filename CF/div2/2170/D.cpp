#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int N = 3e5 + 5;

// 记录以 r 为右端点的限制中，最大的 l
int max_l[N]; 
ll dp[N]; // dp[i] 表示第 i 位是新的一块的起点的方案数

void solve() {
    int n, m;
    cin >> n >> m;
    // 初始化
    for (int i = 0; i <= n + 1; ++i) {
        max_l[i] = 0;
        dp[i] = 0;
    }
    // 更新每个右端点的最右的左端点
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        max_l[r] = max(max_l[r], l);
    }
    // 连通右端点应该共享最右的左端点
    for (int i = 1; i <= n; ++i) {
        max_l[i] = max(max_l[i], max_l[i-1]);
    }
    // 以1为右端点
    dp[1] = 2; 
    
    ll current_sum = 2;
    int left_ptr = 1;

    // dp[3] = dp[1] + dp[2] 其中dp[1]: 11 | 00 , dp[2] : 01 | 10 dp[i]代表新块的起点, 要求新块与旧块的数字不同, dp[3] = 110 001(dp[1]) + 010 101(dp[2])
    for (int i = 2; i <= n + 1; ++i) {
        int threshold = max_l[i-1]; // 旧的区间的左端点就是阈值
        while (left_ptr <= threshold) { // 超出了限制区域, 限制区域要求混色, 所以dp[i]的i必须>threshold
            current_sum = (current_sum - dp[left_ptr] + MOD) % MOD;
            left_ptr++;
        }
        dp[i] = current_sum;
        if (i <= n) {
            current_sum = (current_sum + dp[i]) % MOD;
        }
    }

    cout << dp[n + 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}