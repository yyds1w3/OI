#include <bits/stdc++.h>
using namespace std;

const int N = 20005;
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, n, x;
    cin >> v >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = v; j >= x; --j) {
            dp[j] = max(dp[j], dp[j - x] + x);
        }
    }

    cout << v - dp[v];
}
