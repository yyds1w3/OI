#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int N = 1e3 + 1;
int dist[N][N];
char M[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

void bfs(int x, int y){  
    queue<pair<int, int>> pq;
    pq.push({x, y});
    dist[x][y] = 0;
    while (!pq.empty()){
        pair<int, int> curr = pq.front();
        pq.pop();
        for (int i = 0; i < 4; ++i){
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (M[nx][ny] != '0' && dist[nx][ny] == -1){
                pq.push({nx, ny});
                dist[nx][ny] = dist[curr.first][curr.second] + 1;
            }
        }
    }
}
int main(){
    IOS
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            cin >> M[i][j];
    }
    memset(dist, -1, sizeof(dist));
    int count = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (dist[i][j] == -1 && M[i][j] != '0'){
                count++;
                bfs(i, j);
            }
        }
    }
    cout << count;
}