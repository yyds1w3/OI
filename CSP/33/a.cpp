#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 101;
int n, m, l;
int t1[N], t2[N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> l;
        int a;
        bool vis[N];
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= l; ++j){
            cin >> a;
            if (!vis[a]){
                t1[a]++;
                vis[a] = true;
            }
            t2[a]++;
        }
    }
    for (int i = 1; i <= m; ++i){
        cout << t1[i] << " " << t2[i] << '\n';
    }
}
int main(){
    solve();
}
