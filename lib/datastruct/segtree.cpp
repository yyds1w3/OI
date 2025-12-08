/**
 * Algorithm: Segtree (Range Add + Range Mul)
 * Verified: Luogu P3373
 * Complexity: O(M log N)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// ========================start=============================
struct SegTree {
    int n;
    ll MOD;

    vector<ll> tree, lazy_add, lazy_mul;

    void init(int _n, ll _mod, const vector<ll>& a) {
        n = _n;
        MOD = _mod;
        tree.assign(4 * n + 1, 0);
        lazy_add.assign(4 * n + 1, 0);
        lazy_mul.assign(4 * n + 1, 1);
        build(1, 1, n, a);
    }

    void push_up(int p) {

        tree[p] = (tree[p << 1] + tree[p << 1 | 1]) % MOD;
    }

    void push_down(int p, int len) {
        int ls = p << 1;
        int rs = p << 1 | 1;
        int len_l = len - (len >> 1);
        int len_r = len >> 1;

        if (lazy_mul[p] != 1) {
            tree[ls] = tree[ls] * lazy_mul[p] % MOD;
            tree[rs] = tree[rs] * lazy_mul[p] % MOD;

            lazy_mul[ls] = lazy_mul[ls] * lazy_mul[p] % MOD;
            lazy_mul[rs] = lazy_mul[rs] * lazy_mul[p] % MOD;

            lazy_add[ls] = lazy_add[ls] * lazy_mul[p] % MOD;
            lazy_add[rs] = lazy_add[rs] * lazy_mul[p] % MOD;

            lazy_mul[p] = 1;
        }

        // 再处理加法
        if (lazy_add[p] != 0) {
            tree[ls] = (tree[ls] + lazy_add[p] * len_l) % MOD;
            tree[rs] = (tree[rs] + lazy_add[p] * len_r) % MOD;

            lazy_add[ls] = (lazy_add[ls] + lazy_add[p]) % MOD;
            lazy_add[rs] = (lazy_add[rs] + lazy_add[p]) % MOD;

            lazy_add[p] = 0;
        }
    }

    void build(int p, int l, int r, const vector<ll>& a) {
        lazy_add[p] = 0; lazy_mul[p] = 1;
        if (l == r) {
            tree[p] = a[l] % MOD;
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, a);
        build(p << 1 | 1, mid + 1, r, a);
        push_up(p);
    }

    void update_mul(int p, int l, int r, int ql, int qr, ll k) {
        if (ql <= l && r <= qr) {
            tree[p] = tree[p] * k % MOD;
            lazy_mul[p] = lazy_mul[p] * k % MOD;
            lazy_add[p] = lazy_add[p] * k % MOD;
            return;
        }
        push_down(p, r - l + 1);
        int mid = (l + r) >> 1;
        if (ql <= mid) update_mul(p << 1, l, mid, ql, qr, k);
        if (qr > mid)  update_mul(p << 1 | 1, mid + 1, r, ql, qr, k);
        push_up(p);
    }

    void mult(int ql, int qr, ll k) {
        update_mul(1, 1, n, ql, qr, k);
    }

    void update_add(int p, int l, int r, int ql, int qr, ll k) {
        if (ql <= l && r <= qr) {
            // 【修正】加括号：(tree + k * len) % MOD
            tree[p] = (tree[p] + (r - l + 1) * k) % MOD;
            lazy_add[p] = (lazy_add[p] + k) % MOD;
            return;
        }
        push_down(p, r - l + 1);
        int mid = (l + r) >> 1;
        if (ql <= mid) update_add(p << 1, l, mid, ql, qr, k);
        if (qr > mid)  update_add(p << 1 | 1, mid + 1, r, ql, qr, k);
        push_up(p);
    }

    void add(int ql, int qr, ll k) {
        update_add(1, 1, n, ql, qr, k);
    }

    ll query_fun(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[p];
        }
        push_down(p, r - l + 1);
        int mid = (l + r) >> 1;
        ll res = 0;
        if (ql <= mid) res = (res + query_fun(p << 1, l, mid, ql, qr)) % MOD;
        if (qr > mid)  res = (res + query_fun(p << 1 | 1, mid + 1, r, ql, qr)) % MOD;
        return res;
    }

    ll query(int ql, int qr) {
        return query_fun(1, 1, n, ql, qr);
    }
};
// =====================End=================================
int main() {
    IOS;
    int n, q, m;
    cin >> n >> q >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    SegTree seg;
    seg.init(n, m, a);
    for (int i = 1; i <= q; ++i) {
        int op, x, y;
        ll k;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            seg.mult(x, y, k);
        } else if (op == 2) {
            cin >> x >> y >> k;
            seg.add(x, y, k);
        } else if (op == 3) {
            cin >> x >> y;
            cout << seg.query(x, y) << '\n';
        }
    }
    return 0;
}