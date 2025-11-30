#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 2e5 + 5;
struct Edge{
    int u, v, w;
    bool operator<(const Edge& a) const{
        return w < a.w;
    }
};
vector<Edge> Edges;
int n, m, u, v, w;
int fa[N];
void init(){
    for (int i = 1; i <= n; ++i){
        fa[i] = i;
    }
}
int find(int x){
    if (fa[x] == x){
        return x;
    }else{
        fa[x] = find(fa[x]);
        return fa[x];
    }
}
void join(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY){
        fa[rootX] = rootY;
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> u >> v >> w;
        Edges.push_back({u, v, w});
    }
    init();
    sort(Edges.begin(), Edges.end());
    int ans = 0;
    int edge_num = 0;
    for (auto Edge : Edges){
        if (find(Edge.u) != find(Edge.v)){
            join(Edge.u, Edge.v);
            ans += Edge.w;
            edge_num += 1;
        }
    }
    edge_num < n - 1 ? cout << "orz" : cout << ans;
}