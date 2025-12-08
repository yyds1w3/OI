/**
 * Algorithm: Fenwick Tree (Binary Indexed Tree)
 * Verified: Luogu P3374
 * Complexity: O(log N)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ======================start ==================================
struct BIT {
    int n;
    vector<ll> tree;

    void init(int _n) {
        n = _n;
        tree.assign(n + 1, 0);
    }

    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, ll k) {
        while (x <= n) {
            tree[x] += k;
            x += lowbit(x);
        }
    }
    ll query(int x) {
        ll res = 0;
        while (x > 0) {
            res += tree[x];
            x -= lowbit(x); 
        }
        return res;
    }
    ll query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    
    BIT bit;
    bit.init(n);
    
    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        bit.add(i, val);
    }
    
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) { 
            bit.add(x, y);
        } else { 
            cout << bit.query(x, y) << "\n";
        }
    }
    return 0;
}