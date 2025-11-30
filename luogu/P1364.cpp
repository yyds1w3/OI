#define DP_METHOD 0
#define DFS_METHOD 1
#if DP_METHOD
#include <iostream> 
#include <vector>
using namespace std;
typedef long long ll;
/*
dfs1， 求出某一个节点到其他所有节点的深度和
dfs2,  通过每个节点的子树来动态修改每个节点到其他所有节点的深度和
*/

const int N = 101;
int W[N]; // 每个节点的权值
ll total_weight = 0;
int n, siz[N]; // n为结点总数, 每个节点为根的子树大小
ll dp[N], ans[N]; // dp子树所有点到u的距离和， 全树内所有点到u的距离和
vector<int> g[N], centroids; // 邻接表存储, 重心(可能有俩个)

void dfs1(int u, int fa){ // 更新所有节点的dp, siz
    siz[u] = W[u];
    dp[u] = 0;
    for (int v : g[u]){
        if (v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v]; // 
        dp[u] += dp[v] + siz[v]; // v以下的节点到v是dp[v], v以下及v到u是siz[v]; 
    }
}

void dfs2(int u, int fa){ // 换根计算所有节点的dp
    for (int v : g[u]){
        if (v == fa) continue;
        // -siz[v]v的子树少走一步, (n-siz[v])v之外的子树多走一步
        ans[v] = ans[u] - siz[v] + (total_weight - siz[v]);
        dfs2(v, u);
    }
}

void get_centroids(){
    dfs1(1, 0); // 求出以第一个结点为根的dp
    ans[1] = dp[1];
    dfs2(1, 0); // 动态更新每个结点的dp(ans)

    ll mini = ~(1LL << 63);
    for (int i = 1; i <= n; ++i){
        if (ans[i] < mini){
            mini = ans[i];
            centroids = {i};
        }else if(ans[i] == mini){
            centroids.push_back(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    int w, u, v;
    for (int i = 1; i <= n; ++i){
        cin >> w >> u >> v;
        W[i] = w;
        total_weight += w;
        if (u) {g[i].push_back(u); g[u].push_back(i);}
        if (v) {g[i].push_back(v); g[v].push_back(i);}
    }
    get_centroids();
    if (!centroids.empty()){
        cout << ans[centroids[0]];
    }
}



#endif // DP_METHOD

#if DFS_METHOD
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 50005;

int n;
int siz[MAXN],  // 这个节点的「大小」（所有子树上节点数 + 该节点）
    weight[MAXN];  // 这个节点的「重量」，即所有子树「大小」的最大值
vector<int> centroids;  // 用于记录树的重心（存的是节点编号）
vector<int> g[MAXN]; // 记录每个点的相连点， 邻接表

//  记录每个节点的weight
void dfs(int cur, int fa) {  // cur 表示当前节点 (current)
  siz[cur] = 1;
  weight[cur] = 0;
  for (int v : g[cur]) {
    if (v != fa) {  // v 表示这条有向边所通向的节点
      dfs(v, cur);
      siz[cur] += siz[v];
      weight[cur] = max(weight[cur], siz[v]); // 最重的子树
    }
  }
  weight[cur] = max(weight[cur], n - siz[cur]); // 比较上下两头的子树，取重的
  if (weight[cur] <= n / 2) {  // 依照树的重心的定义统计
    centroids.push_back(cur);
  }
}

void get_centroids() { dfs(1, 0); }

#endif
