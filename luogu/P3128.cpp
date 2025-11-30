#include <iostream> // 改成 iostream 更通用
#include <vector>
#include <algorithm> // for swap
using namespace std;

const int N = 50005; // 题目范围 5e4
vector<int> adj[N];
int depth[N]; // 根节点depth == 1
int up[N][25]; // up[u][i]代表u节点向上跳2 ^ i之后的节点
int diff[N];
int milk[N];
int ans;
int n, k, x, y, s, t;

void dfs(int u, int fa){
    // 初始化
    depth[u] = depth[fa] + 1;
    up[u][0] = fa;
    // 开始修到根节点的梯子
    for (int i = 1; i <= 20; ++i){
        // log级别修梯子：先跳 2^(i-1)，再跳 2^(i-1)
        up[u][i] = up[ up[u][i-1] ][i-1]; 
    }
    // 开始给子节点修梯子
    for (int v : adj[u]){
        if (v != fa) dfs(v, u);
    }
}

int lca(int u, int v){
    // 统一u在下面 (深度更大)
    if (depth[u] < depth[v]) swap(u, v);
    
    // 让u向上跳直到和v同一层
    for (int i = 20; i >= 0; --i){
        // 如果跳完之后深度依然 >= v 的深度，那就跳
        if (depth[ up[u][i] ] >= depth[v]){
            u = up[u][i];
        }
    }
    
    // 1.当u和v同一层发现一样, 那么v就是u的祖先
    if (u == v) return v;
    
    // 2.u和v同一层不一样, 两个一起向上跳, 直到LCA的下方
    for (int i = 20; i >= 0; --i){
        // 跳的不够高 (还没相遇)，继续跳
        if (up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    
    // 最后u和v都在LCA的下方了，再往上一步就是 LCA
    return up[u][0];
}
void dfs_sum(int u, int fa){
    for (int v : adj[u]){
        if (v != fa){
            dfs_sum(v, u);
            diff[u] += diff[v]; // 回溯, 差分求前缀和
        }
    }
    ans = max(ans, diff[u]);
}
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n - 1; ++i){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= k; ++i){
        cin >> s >> t;
        diff[s]++;
        diff[t]++;
        diff[lca(s, t)]--;
        diff[up[lca(s, t)][0]]--;
    }
    dfs_sum(1, 0);
    cout << ans;
}