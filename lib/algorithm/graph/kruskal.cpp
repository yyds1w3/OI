/**
 * Algorthim: Kruskal
 * Verified: Luogu P3366
 * Complexity: O(E log E)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// =============start===============
struct Edge{
    int u, v, w;
    bool operator<(const Edge& other) {return w < other.w;}
};
struct Kruskal{
    int n;
    vector<Edge> edges;
    vector<int> fa;

    void init(int _n){
        n = _n;
        edges.clear();
        fa.assign(n+1, 0);
        for (int i = 1; i <= n; ++i) fa[i] = i;
    }
    void add_edge(int u, int v, int w){
        edges.push_back({u, v, w});
    }
    int find(int x){
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    ll solve(){
        sort(edges.begin(), edges.end());
        ll total_weight = 0;
        int count = 0;

        for (auto &e : edges){
            int rootX = find(e.u);
            int rootY = find(e.v);
            if (rootX != rootY){
                fa[rootY] = rootX;
                total_weight += e.w;
                count++;
            }
        }
        if (count < n - 1) return -1;
        return total_weight;
    }
};

// ===============End==================
int main(){
    IOS;
    int n, m;
    cin >> n >> m;
    Kruskal kru;
    kru.init(n);
    int x, y, z;
    for (int i = 1; i <= m; ++i){
        cin >> x >> y >> z;
        kru.add_edge(x, y, z);
    }
    ll ans = kru.solve();
    ans == -1 ? cout << "orz" : cout << ans;
}