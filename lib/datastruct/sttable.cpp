/**
 * Algorithm: ST table for RMQ(区间最大值)
 * Verified: Luogu P3865
 * Complexity: build O(N log N), Query(1)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// ========================start==========================
const int MAXN = 1e5 + 5;
const int LOG = 20;
struct ST {
    int f[MAXN][LOG]; // f[i][j] 表示 [i, i + 2^j - 1] 的最大值
    int lg[MAXN];

    void init(int n, const vector<int> &a){
        lg[1] = 0;
        for (int i = 2; i <= n; ++i){
            lg[i] = lg[i/2] + 1;
        }
        for (int i = 1; i <= n; ++i){
            f[i][0] = a[i];
        }
        for (int j = 1; j < LOG; ++j){ // 从小区间慢慢变成大区间
            for (int i = 1; i + (1 << j) - 1 <= n; ++i){
                f[i][j] = max(f[i][j-1], f[i + (1 << (j-1))][j-1]);
            }
        }
    }
    int query(int l, int r){
        int k = lg[r - l + 1];
        return max(f[l][k], f[r - (1 << k) + 1][k]); // [l, l+2^k-1] [r-(2^k-1), r] sz = 2^k >= len / 2
    }
};
// ======================End================================
int main(){
    IOS;
    int n, m, l, r;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ST st;
    st.init(n, a);
    for (int i = 1; i <= m; ++i){
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
}