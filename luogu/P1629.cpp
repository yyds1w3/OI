#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e3+5;
int n, m;
ll ans;
struct Edge{
    int v, w;
    bool operator<(const Edge& other) const {return w > other.w;}
};
vector<Edge> adj[N];
vector<Edge> radj[N];
int dist1[N];
int dist2[N];
void init_adj(){
    int u, v, w;
    for (int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
    }
}
void dijkstra(int start, vector<Edge> graph[], int dist[]){
    priority_queue<Edge> pq;
    memset(dist, 0x3f, sizeof(int) * N);
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()){
        Edge curr = pq.top();
        pq.pop();
        if (curr.w > dist[curr.v]) continue;
        for (auto edge : graph[curr.v]){
            if (dist[curr.v] + edge.w < dist[edge.v]){
                dist[edge.v] = dist[curr.v] + edge.w;
                pq.push({edge.v, dist[edge.v]});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    init_adj();
    dijkstra(1, adj, dist1);
    dijkstra(1, radj, dist2);
    for (int i = 2; i <= n; ++i){
        ans += dist1[i] + dist2[i];
    }
    cout << ans;
}