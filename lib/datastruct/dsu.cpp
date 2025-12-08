/**
 * Algorthim: DSU (Disjoint Set Union)
 * Verified: Luogu P3367
 * Complexity: O(N) but nearly ==> O(1)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// ================ start=====================
struct DSU{
    vector<int> fa, sz;
    void init(int n){
        fa.assign(n+1, 0);
        sz.assign(n+1, 1);
        for (int i = 1; i <= n; ++i) fa[i] = i;
    }

    int find(int x){
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    bool merge(int x, int y){ // y认x是老大
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        fa[rootY] = rootX;
        sz[rootX] += sz[rootY];
        return true;
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    bool size(int x){
        return sz[find(x)];
    }
};
// ========================End=======================

int main(){
    IOS;
    int n, m, x, y, z;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    for (int i = 1; i <= m; ++i){
        cin >> z >> x >> y;
        if (z == 1){
            dsu.merge(x, y);
        }else if (z == 2){
            dsu.same(x, y) ? cout << "Y" : cout << "N";
            cout << '\n';
        }
    }
}