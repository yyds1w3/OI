#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m, s;
int u, v, w;
struct Point{
    int u, w;
    bool operator> (const Point& a) const{
        return w > a.w;
    }
};
vector<Point> adj[N];
priority_queue<Point, vector<Point>, greater<Point>> pq;
int dist[N];
void bfs_dli(){
    pq.push({s, 0});
    dist[s] = 0;
    while(!pq.empty()){
        Point curr = pq.top();
        pq.pop();
        if (curr.w > dist[curr.u]) continue; // 刚取出来的比原来的还大就不要了, 比如第一次存的是5, 后来更新成了3，就要选3的
        for (auto edge : adj[curr.u]){
            if (dist[curr.u] + edge.w < dist[edge.u]){ // 新路径更小
                dist[edge.u] = dist[curr.u] + edge.w;
                pq.push({edge.u, dist[edge.u]});  // 把最新的最小路径存进去,作为新的起点,如果新路径是绕路就不会存
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << dist[i] << " ";
    }
}
int main(){
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    memset(dist, 0x3f, sizeof(dist));
    bfs_dli();
}