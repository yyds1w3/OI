#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e3+5;
int n, m, k, x, y, l;
ll ans = 0, sub = 0;
int fa[N];
struct Edge{
    int u, v, w;
    bool operator<(const Edge& other) {return w < other.w;}
};
vector<Edge> Edges;
void init(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i){
        cin >> x >> y >> l;
        Edges.push_back({x, y, l});
    }
}
int find(int x){
    if (fa[x] == x){
        return x;
    }
    return fa[x] = find(fa[x]);
}
void join(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY){
        fa[rootX] = rootY;
    }
}

void kruskal(){
    if (n == k){
        cout << 0;
        return;
    }else if (n < k){
        cout << "No Answer";
        return;
    }
    sort(Edges.begin(), Edges.end());
    for (auto e : Edges){
        if (find(e.u) != find(e.v)){
            join(e.u, e.v);
            ans += e.w;
            sub++;
            if (sub == n - k){
                cout << ans;
                return;
            }
        }
    }
    cout << "No Answer";
}

int main(){
    init();
    kruskal();
}