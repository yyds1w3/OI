#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, m, k;
class DSU{
public:
    vector<int> fa;
    vector<int> sz;
    DSU(int n){
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        iota(fa.begin(), fa.end(), 0); // 0 1 2 3 ... n
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
            sz[rootY] += sz[rootX];       
        }
    }
    int getSize(int x){
        return sz[find(x)];
    }
};
int main(){
    IOS
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 1; i <= m; ++i){
        cin >> k;
        if (k == 0) continue;
        int head;
        cin >> head;
        k--;
        int tail;
        while(k){
            cin >> tail;
            dsu.join(tail, head);
            k--;
        }
    }
    for (int i = 1; i <= n; ++i){
        cout << dsu.getSize(i) << ' ';
    }
}