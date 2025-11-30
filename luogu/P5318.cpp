#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool used[N];
int n ,m, u, v;


void dfs(int u){
    used[u] = true;
    cout << u << " ";
    for (int v : adj[u]){
        if (!used[v]){
            dfs(v);
        }
    }
}
void bfs(){
    queue<int> q;
    q.push(1);
    used[1] = true;
    while(!q.empty()){
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int v : adj[u]){
            if (!used[v]){
                q.push(v);
                used[v] = true;
            }
        }
    }
    cout << endl;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i){
        if (!adj[i].empty())
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(1);
    cout << endl;
    memset(used, false, sizeof(used));
    bfs();
}