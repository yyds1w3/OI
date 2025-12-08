/**
 * Algorthim: LCA
 * Verified: Luogu P3379
 * Complexity: Build O(N log N), Query(log N)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// =============start===============
const int MAXN = 5e5 + 5;
const int LOG = 20;

struct LCA{
    int n;
    vector<int> adj[MAXN];
    int up[MAXN][LOG];
    int depth[MAXN];

    void init(int _n){
        n = _n;
        for (int i = 0; i <= n; ++i) adj[i].clear();
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // u节点, p父节点, d深度
    void dfs(int u, int p, int d){
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i){
            up[u][i] = up[up[u][i-1]][i-1];
        }
        for (int v : adj[u]){
            if (v == p) continue;
            dfs(v, u, d+1);
        }
    }
    void build(int root){
        dfs(root, root, 1);// 父亲设置成根节点套娃
    }
    int get_lca(int u, int v){
        if (depth[u] < depth[v]) swap(u, v);

        for (int i = LOG - 1; i >= 0; --i){
            if (depth[u] - (1 << i) >= depth[v]){ // u在v及下面
                u = up[u][i];
            }
        }
        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; --i){ // 同一起跑线
            if (up[u][i] != up[v][i]){ // 还没有合并
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};

// ===============End==================
int main(){
    IOS;
    int n, m, s;
    cin >> n >> m >> s;
    int x, y;
    LCA lca;
    lca.init(n);
    for (int i = 1; i <= n - 1; ++i){
        cin >> x >> y;
        lca.add_edge(x, y);
    }
    lca.build(s);
    for (int i = 1; i <= m; ++i){
        cin >> x >> y;
        cout << lca.get_lca(x, y) << '\n';
    }

}