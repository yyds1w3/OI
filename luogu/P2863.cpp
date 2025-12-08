#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int dfn[N], low[N]; // dfn是dfs第几个, low是不走回头路可以到的最远节点
int timestamp;
stack<int> stk; // 根据在栈中来判断是否是未完成的scc
bool in_stack[N];

int scc_count; // scc 的idx
int scc_id[N]; // 每个节点对应的sccidx
int scc_size[N]; // 每个节点对应的sccidx对应的大小

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;   
    stk.push(u);
    in_stack[u] = true;
    for (int v : adj[u]){ // 遍历每个边
        if (!dfn[v]){ // 未访问过
            tarjan(v); // 递归访问
            low[u] = min(low[u], low[v]); // 回溯更新low
        } else if(in_stack[v]){ // 在我们的未完成的scc中
            low[u] = min(low[u], dfn[v]);  // 更新low
        }
    }
    if (dfn[u] == low[u]){ // 根节点
        scc_count++; 
        int y;
        // 将u之上的所有节点弹出，并且合并成一个scc强连通分量
        do{
            y = stk.top(); 
            stk.pop();
            in_stack[y] = false;
            scc_id[y] = scc_count;
            scc_size[scc_count]++;
        } while(y != u);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int ans = 0;
    for(int i = 1; i <= scc_count; i++){
        if(scc_size[i] > 1) ans++;
    }
    cout << ans << endl;
    
    return 0;
}