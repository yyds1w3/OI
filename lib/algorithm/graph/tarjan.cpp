/**
 * Algorthim: Tarjan(SCC)
 * Verified: Luogu P2863
 * Complexity: O(N + M)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// ================start=======================
struct Tarjan{
    int n, cnt, scc_cnt;
    vector<vector<int>> adj;
    vector<int> dfn, low, belongs;
    vector<int> stk;
    vector<bool> in_stk;
    vector<int> scc_size;

    void init(int _n){
        n = _n;
        cnt = scc_cnt = 0;
        adj.assign(n + 1, vector<int>());
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        belongs.assign(n + 1, 0);
        in_stk.assign(n + 1, false);
        scc_size.assign(n + 1, 0);
        stk.clear();
    }

    void add_edge(int u, int v){
        adj[u].push_back(v);
    }

    void dfs(int u){
        dfn[u] = low[u] = ++cnt;
        stk.push_back(u);
        in_stk[u] = true;
        for (int v : adj[u]){
            if (!dfn[v]){
                dfs(v);
                low[u] = min(low[u], low[v]);
            }else if(in_stk[v]){
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]){
            scc_cnt++;
            int v;
            do{
                v = stk.back();
                stk.pop_back();
                in_stk[v] = false;
                belongs[v] = scc_cnt;
                scc_size[scc_cnt]++;
            }while(v != u);
        }
    }
    void solve(){
        for (int i = 1; i <= n; ++i){
            if (!dfn[i]) dfs(i);
        }
    }
}tar;

// ======================End===========================
int main(){
    IOS;
    int n, m;
    cin >> n >> m;
    tar.init(n);
    for (int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        tar.add_edge(a, b);
    }
    tar.solve();
    int ans = 0;
    for (int i = 1; i <= tar.scc_cnt; ++i){
        if (tar.scc_size[i] > 1) ans++;
    }
    cout << ans;
}