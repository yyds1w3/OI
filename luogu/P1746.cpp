#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
const int N = 1e3 + 1;
queue<pair<int, int>> pq;
int dist[N][N];
char M[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int sx, sy, ex, ey;
void bfs(){
    pq.push({sx, sy});
    dist[sx][sy] = 0;
    while (!pq.empty()){
        pair<int, int> curr = pq.front();
        pq.pop();
        if (curr.first == ex && curr.second == ey){
            cout << dist[ex][ey] << endl;
            return;
        }
        for (int i = 0; i < 4; ++i){
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (M[nx][ny] != '1' && nx >= 1 && nx <= n && ny >= 1 && ny <= n && dist[nx][ny] == -1){
                pq.push({nx, ny});
                dist[nx][ny] = dist[curr.first][curr.second] + 1;
            }
        }
    }
    cout << dist[ex][ey];
}
int main(){
    IOS
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j)
            cin >> M[i][j];
    }
    cin >> sx >> sy >> ex >> ey;
    memset(dist, -1, sizeof(dist));
    bfs();
}