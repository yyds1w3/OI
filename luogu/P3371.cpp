#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
// 0x3f3f3f3f 约为 10亿，两个相加不会爆 int，且可以用 memset 赋值
const int INF = 0x3f3f3f3f; 

struct Edge {
    int v, w; // v: 邻居编号, w: 边权
};

// 全局变量
vector<Edge> adj[N];  // 邻接表
int dist[N];          // 记录最短距离
bool in_queue[N];     // 记录某个点当前是否在队列中 (SPFA 核心)
int n, m, s;

void spfa(int s) {
    // 1. 初始化
    // dist 初始化为无穷大
    memset(dist, 0x3f, sizeof(dist));
    // in_queue 初始化为 false
    memset(in_queue, false, sizeof(in_queue));

    dist[s] = 0;

    // 2. 队列处理
    queue<int> q;
    q.push(s);
    in_queue[s] = true; // 【关键】入队立刻标记

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // 【关键差异点】Dijkstra 出队是永久完结，但 SPFA 出队只是暂停
        // 我们需要把标记取消，因为如果后面 u 的距离又变短了，它还得回来重新排队
        in_queue[u] = false; 

        for (auto edge : adj[u]) {
            int v = edge.v;
            int w = edge.w;

            // 【松弛操作】(和 Dijkstra 一模一样)
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                // 【入队判断】
                // 只有当 v 不在队列里时，才把它放进去
                // 作用：防止队列里堆积了 100 个 v，浪费时间
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true; // 进队标记
                }
            }
        }
    }
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); 
        // 洛谷 P3371 是有向图。如果是无向图题，记得加下面这行：
        // adj[v].push_back({u, w});
    }

    spfa(s);

    // 输出结果
    for (int i = 1; i <= n; ++i) {
        // 洛谷题目通常要求：如果无法到达，输出 2^31-1 (即 INT_MAX)
        if (dist[i] == INF) {
            cout << 2147483647 << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}