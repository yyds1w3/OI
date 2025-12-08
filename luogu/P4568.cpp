#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
const int K = 11;
const int INF = 0x3f3f3f3f;
int n, m, k, s, t;
int dist[N][K];
vector<pair<int, int>> adj[N];
struct Node{
    int u;
    int d; 
    int k;
    bool operator<(const Node& other) const {
        return d > other.d; 
    }
};
void dijkstra(int s){
    memset(dist, 0x3f, sizeof(dist)); 
    priority_queue<Node> pq;
    dist[s][0] = 0;
    pq.push({s, 0, 0}); 
    while(!pq.empty()){
        Node curr = pq.top();
        pq.pop();
        int u = curr.u; 
        if (curr.d > dist[u][curr.k]) continue;
        for (auto edge: adj[u]){ 
            int v = edge.first;
            int w = edge.second;
            if (dist[v][curr.k] > dist[u][curr.k] + w){
                dist[v][curr.k] = dist[u][curr.k] + w;
                pq.push({v, dist[v][curr.k], curr.k});
            }
            if (curr.k < k && dist[v][curr.k+1] > dist[u][curr.k]){
                dist[v][curr.k+1] = dist[u][curr.k];
                pq.push({v, dist[v][curr.k+1], curr.k + 1});
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <=  k; ++i){
        ans = min(ans, dist[t][i]);
    }
    cout << ans;
}
void solve(){
    cin >> n >> m >> k >> s >> t;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(s);
}
int main(){
    IOS
    solve();
}