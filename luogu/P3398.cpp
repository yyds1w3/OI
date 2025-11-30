#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
vector<int> adj[N];
int depth[N], up[N][25];
int n, q;
void dfs(int u, int fa) {
    depth[u] = depth[fa] + 1;
    up[u][0] = fa;
    for (int i = 1; i <= 20; ++i) 
        up[u][i] = up[up[u][i-1]][i-1];
    
    for (int v : adj[u]) {
        if (v != fa) dfs(v, u);
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 20; i >= 0; --i) 
        if (depth[up[u][i]] >= depth[v]) u = up[u][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; --i) 
        if (up[u][i] != up[v][i]) { u = up[u][i]; v = up[v][i]; }
    return up[u][0];
}
int get_dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
bool on_path(int x, int u, int v) {
    return get_dist(u, x) + get_dist(x, v) == get_dist(u, v);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0); 
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = lca(a, b);
        int y = lca(c, d);
        if (on_path(x, c, d) || on_path(y, a, b)) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}