#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10005;
vector<int> adj[N];
queue<int> q;
int in[N];
int len[N];
int dp[N];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i){
        int u, w, v;
        cin >> u >> w;
        len[u] = w;
        while (cin >> v && v != 0){
            in[u]++;
            adj[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; ++i){
        if (in[i] == 0){
            q.push(i);
            dp[i] = len[i];
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            dp[v] = max(dp[v], dp[u] + len[v]);
            in[v]--;
            if (in[v] == 0){
                q.push(v);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    
    return 0;
}