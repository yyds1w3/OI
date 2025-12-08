/**
 * Algorthim: Dijkstra (Priority Queue Optimized)
 * Verified: Luogu P4779
 * Complexity: O(E log V)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// ==================start========================

const ll INF = 1e18;

struct Edge{
    int to;
    ll w;
    bool operator<(const Edge& other) const {return w > other.w;}
};

struct Dijkstra{
    int n;
    vector<vector<Edge>> adj;
    vector<ll> dist;

    void init(int _n){
        n = _n;
        adj.assign(n+1, vector<Edge>());
        dist.assign(n+1, INF);
    }

    void add_edge(int u, int v, ll w){
        adj[u].push_back({v, w}); // 单向边
    }

    void solve(int s){
        priority_queue<Edge> pq;
        dist[s] = 0;
        pq.push({s, 0});
        while (!pq.empty()){
            Edge edge = pq.top();
            pq.pop();
            if (edge.w > dist[edge.to]) continue;
            for (auto &e : adj[edge.to]){
                if (e.w + dist[edge.to] < dist[e.to]){
                    dist[e.to] = e.w + dist[edge.to];
                    pq.push({e.to, dist[e.to]});
                }
            }
        }
    }
};

// ====================End======================

int main(){
    IOS;
    int n, m, s;
    cin >> n >> m >> s;
    Dijkstra dij;
    dij.init(n);
    int u, v;
    ll w;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        dij.add_edge(u, v, w);
    }
    dij.solve(s);
    for (int i = 1; i <= n; ++i){
        cout << dij.dist[i] << ' ';
    }
}