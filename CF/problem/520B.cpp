#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int dist[N * 2];
int n, m;
void bfs(int s){
    memset(dist, 0xff, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int sm = q.front();
        if (sm == m) break;
        q.pop();
        if (sm < N && dist[2 * sm] == -1){
            q.push(2 * sm);
            dist[2 * sm] = dist[sm] + 1;
        }
        if (sm != 0 && dist[sm - 1] == -1){
            q.push(sm - 1);
            dist[sm - 1] = dist[sm] + 1;
        }
    }
}
void solve(){
    cin >> n >> m;
    bfs(n);
    cout << dist[m];
}
int main(){
    IOS
    solve();
    
}