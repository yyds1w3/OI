#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; 
vector<int> adj[N];
vector<int> dag_adj[N];
int dfn[N], low[N], w[N], timestamp;
stack<int> stk;
bool in_stack[N];
int scc_count;
int scc_id[N];
int scc_size[N];
int scc_weight[N];
int memo[N];
void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;   
    stk.push(u);
    in_stack[u] = true; 
    for (int v : adj[u]){
        if (!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in_stack[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]){
        scc_count++; 
        int y;
        do {
            y = stk.top(); 
            stk.pop();
            in_stack[y] = false;
            scc_id[y] = scc_count;
            scc_size[scc_count]++;
            scc_weight[scc_count] += w[y]; 
        } while(y != u);
    }
}

void build_dag(int n){
    for (int u = 1; u <= n; ++u){
        for (int v : adj[u]){ 
            int x = scc_id[u];
            int y = scc_id[v];
            if (x != y){
                dag_adj[x].push_back(y);
            }
        }
    }
    for (int i = 1; i <= scc_count; i++) {
        sort(dag_adj[i].begin(), dag_adj[i].end());
        dag_adj[i].erase(unique(dag_adj[i].begin(), dag_adj[i].end()), dag_adj[i].end());
    }
}

int dp(int u){
    if (memo[u]) return memo[u];
    
    int max_future = 0;
    for (int v : dag_adj[u]){
        max_future = max(max_future, dp(v));
    }
    return memo[u] = scc_weight[u] + max_future;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) { // 新的scc
            tarjan(i);
        }
    }
    
    build_dag(n);
    int ans = 0;
    for(int i = 1; i <= scc_count; i++){
        ans = max(ans, dp(i));
    }
    
    cout << ans << endl;
    
    return 0;
}