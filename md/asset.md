# 卡题
- 模拟样例
- 找规律
- 看数据范围
  - 1000 $N^2$
  - $10^5 O(NlogN)二分或者O(N)贪心$
# 基础模板

```cpp
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, m;
int main(){
    IOS;
}
```
# 具体
## 动态规划
### 0-1背包
### 完全背包
### LCS
### LIS
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int mp[N];
int b[N];  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mp[x] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> x;
        b[i] = mp[x];
    }
    vector<int> tail;
    if (n > 0) tail.push_back(b[1]);

    for (int i = 2; i <= n; i++) {
        if (b[i] > tail.back()) {
            tail.push_back(b[i]);
        } 
        else {
            int idx = lower_bound(tail.begin(), tail.end(), b[i]) - tail.begin();
            tail[idx] = b[i]; 
        }
    }

    cout << tail.size() << endl;
    return 0;
}

```

## STL
## 数据结构
### 树
#### 线段树
```cpp
#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

ll tree[N << 2];
ll lazy[N << 2]; // 打上懒标记意味着该节点已经修改, 但是子节点没有, 懒标记只能下放
ll a[N]; 
int n,m,x,y,op;
ll k;
// 左孩子, 右孩子
inline int ls(int p) {return p << 1;}
inline int rs(int p) {return (p << 1) | 1;}
// push_up是把子节点的tree加到父节点
void push_up(int p){
    tree[p] = tree[ls(p)] + tree[rs(p)];
}
// push_down下放懒标记, 使用时一定不是叶子节点
void push_down(int p, int len){
    if (lazy[p]){
        // left
        lazy[ls(p)] += lazy[p];
        tree[ls(p)] += lazy[p] * (len - (len >> 1));
        // right
        lazy[rs(p)] += lazy[p];
        tree[rs(p)] += lazy[p] * (len >> 1);
        // p
        lazy[p] = 0;
    }
}
// p代表本节点, l, r代表管辖a[l ~ r]
void build(int p, int l, int r){
    if (l == r){
        tree[p] = a[l];
        return;
    }
    // 假设l = 1, r = 4, mid = 2
    int mid = (l + r) >> 1;
    build(ls(p), l, mid); // 1~2
    build(rs(p), mid + 1, r); // 3~4
    push_up(p); // 回溯更新父节点
}
// 区间修改[nl, nr] + k
void update(int p, int l, int r, int nl, int nr, ll k){
    if (nl <= l && r <= nr){
        tree[p] += k * (r - l + 1);
        lazy[p] += k;
        return;
    }
    // 没有完全覆盖
    push_down(p, r-l+1); // 下放懒标记
    int mid = (l + r) >> 1; 
    if (nl <= mid) update(ls(p), l, mid, nl, nr, k);
    if (nr >  mid) update(rs(p), mid+1, r, nl, nr, k);
    push_up(p); // 回溯更新父节点
}
ll query(int p, int l, int r, int nl, int nr){
    if (nl <= l && r <= nr) return tree[p];
    push_down(p, r-l+1);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (nl <= mid) res += query(ls(p), l, mid, nl, nr);
    if (nr > mid) res += query(rs(p), mid+1, r, nl, nr);
    // 没有push_up, 因为没有修改, 上方的数据是最新的且不用动
    return res;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; ++i){
        cin >> op;
        if (op == 1){
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }else if (op == 2){
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
}
```
```cpp
#include <iostream>
using namespace std;

typedef long long ll;
const int N = 100005;

ll P;
ll tree[N << 2];
ll add[N << 2];
ll mul[N << 2];
ll a[N]; 
int n, m, op;

inline int ls(int p) {return p << 1;}
inline int rs(int p) {return (p << 1) | 1;}

void push_up(int p){
    tree[p] = (tree[ls(p)] + tree[rs(p)]) % P;
}
void push_down(int p, int len){
    int len_l = len - (len >> 1);
    int len_r = len >> 1;
    if (mul[p] != 1) { // 乘法不用乘以区间长度，因为线段树维护的区间和
        // left
        tree[ls(p)] = (tree[ls(p)] * mul[p]) % P;
        mul[ls(p)]  = (mul[ls(p)] * mul[p]) % P;
        add[ls(p)]  = (add[ls(p)] * mul[p]) % P;
        // right
        tree[rs(p)] = (tree[rs(p)] * mul[p]) % P;
        mul[rs(p)]  = (mul[rs(p)] * mul[p]) % P;
        add[rs(p)]  = (add[rs(p)] * mul[p]) % P;
        // p
        mul[p] = 1; 
    }

    if (add[p]) {
        // left
        tree[ls(p)] = (tree[ls(p)] + add[p] * len_l) % P; 
        add[ls(p)]  = (add[ls(p)] + add[p]) % P;         
        // right
        tree[rs(p)] = (tree[rs(p)] + add[p] * len_r) % P;
        add[rs(p)]  = (add[rs(p)] + add[p]) % P;
        // p
        add[p] = 0;
    }
}

void build(int p, int l, int r){
    mul[p] = 1;
    add[p] = 0;
    if (l == r){
        tree[p] = a[l] % P;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up(p);
}

void update_mul(int p, int l, int r, int nl, int nr, ll k){
    if (nl <= l && r <= nr){
        tree[p] = (tree[p] * k) % P;
        mul[p]  = (mul[p] * k) % P;
        add[p]  = (add[p] * k) % P;
        return;
    }
    push_down(p, r - l + 1);
    int mid = (l + r) >> 1; 
    if (nl <= mid) update_mul(ls(p), l, mid, nl, nr, k);
    if (nr >  mid) update_mul(rs(p), mid+1, r, nl, nr, k);
    push_up(p);
}

void update_add(int p, int l, int r, int nl, int nr, ll k){
    if (nl <= l && r <= nr){
        tree[p] = (tree[p] + k * (r - l + 1)) % P; 
        add[p]  = (add[p] + k) % P;             
        return;
    }
    push_down(p, r - l + 1);
    int mid = (l + r) >> 1; 
    if (nl <= mid) update_add(ls(p), l, mid, nl, nr, k);
    if (nr >  mid) update_add(rs(p), mid+1, r, nl, nr, k);
    push_up(p);
}

ll query(int p, int l, int r, int nl, int nr){
    if (nl <= l && r <= nr) return tree[p];
    push_down(p, r - l + 1);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (nl <= mid) res = (res + query(ls(p), l, mid, nl, nr)) % P;
    if (nr >  mid) res = (res + query(rs(p), mid+1, r, nl, nr)) % P;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> P;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1, 1, n);

    while(m--){
        int op, x, y;
        ll k;
        cin >> op >> x >> y;
        if (op == 1){ 
            cin >> k;
            update_mul(1, 1, n, x, y, k);
        } else if (op == 2){ 
            cin >> k;
            update_add(1, 1, n, x, y, k);
        } else {
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}
```
### 树状数组
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m;
int tree[N];
int lowbit(int x){
    return x & (-x);
}
// x = 0100(1~4) 则tree[1000](1~8), [0100](1~4)都要更新, 是x的上级
// x = 0110(5~6) 则tree[0110](5~6), [1000](1~8), [1000]
void add(int x, int k){
    while(x <= n){
        tree[x] += k;
        x += lowbit(x);
    }
}
// x = 0110(4~6) 则ans += tree[0110](4~6), [0100](1~4)都要加上
int ask(int x){
    int ans = 0;
    while(x > 0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        int val;
        cin >> val;
        add(i, val);
    }
    int op, x, y;
    for (int i = 1; i <= m; ++i){
        cin >> op >> x >> y;
        if (op == 1){
            add(x, y);
        }else if(op == 2){
            cout << ask(y) - ask(x-1) << '\n';
        }
    }

}
```
### LCA
```cpp
#include <iostream> // 改成 iostream 更通用
#include <vector>
#include <algorithm> // for swap
using namespace std;

const int N = 500005; // 题目范围 5e5
vector<int> adj[N];
int depth[N]; // 根节点depth == 1
int up[N][25]; // up[u][i]代表u节点向上跳2 ^ i之后的节点
int n, m, s, x, y, a, b;

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

int main(){
    // 加速
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; ++i){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(s, 0);

    for (int i = 1; i <= m; ++i){
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}
```
### 点差分
```cpp
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

```
### 边差分
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
vector<int> adj[N];
int depth[N], up[N][25];
int n, q;
void dfs(int u, int fa) {
    depth[u] = depth[fa] + 1;
    up[u][0] = fa;
    for (int i = 1; i <= 20; ++i) 
        up[u][i] = up[up[u][i-1]][i-1];
    
    for (int v : adj[u]) {
        if (v != fa) dfs(v, u);
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 20; i >= 0; --i) 
        if (depth[up[u][i]] >= depth[v]) u = up[u][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; --i) 
        if (up[u][i] != up[v][i]) { u = up[u][i]; v = up[v][i]; }
    return up[u][0];
}
int get_dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
bool on_path(int x, int u, int v) {
    return get_dist(u, x) + get_dist(x, v) == get_dist(u, v);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0); 
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = lca(a, b);
        int y = lca(c, d);
        if (on_path(x, c, d) || on_path(y, a, b)) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}
```
## 静态链表
```cpp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
vector<int> adj[N];
int depth[N], up[N][25];
int n, q;
void dfs(int u, int fa) {
    depth[u] = depth[fa] + 1;
    up[u][0] = fa;
    for (int i = 1; i <= 20; ++i) 
        up[u][i] = up[up[u][i-1]][i-1];
    
    for (int v : adj[u]) {
        if (v != fa) dfs(v, u);
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 20; i >= 0; --i) 
        if (depth[up[u][i]] >= depth[v]) u = up[u][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; --i) 
        if (up[u][i] != up[v][i]) { u = up[u][i]; v = up[v][i]; }
    return up[u][0];
}
int get_dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
bool on_path(int x, int u, int v) {
    return get_dist(u, x) + get_dist(x, v) == get_dist(u, v);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0); 
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = lca(a, b);
        int y = lca(c, d);
        if (on_path(x, c, d) || on_path(y, a, b)) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}
```
## 杂
### 康托展开

### Catlan数
## 头文件
```cpp
#include <iostream>
#include <iomanip>
#include <ios>
// 控制位数
cout << setprecision(3) << fixed << num << endl; // setprecision是有效数字位数， fixed固定小数点，变为了小数点位数
还有scientfic,hexfloat,default的输出方式
// 控制场宽
cout << setw(3) << x; // 占据3个空格, 默认右对齐
cout << left << setw(3) // 左对齐

// cin卡住
cin >> a[i] >> b[i];通常会在最后一个卡住的原因是因为 1 3 的3后面没有空格符号， cin不知道3是你输入的还是3.......是你输入的e'm
```


# memset
```c++
#include <cstring>
memset(A, 0, sizeof(A)); // 注意最后一个参数是字节数
```

# bitset
```cpp
bitset<size> bs; // 默认全为0
bs.set() // 全为1
bs.reset() // 全为0
bs[]


```
# algorithm
```cpp
next_permutation(a, a+n); // 返回下一个全排列 1 2 3 --> 1 3 2
fill(a, a+n, value); // 给容器赋值

```

# numeric
```cpp
gdc / lcm
accumulate(begin, end, init_value); // 求和数组
iota(begin, end, start_value); // 等价a[i] = i
```

## 数学
### 求排列组合数
```cpp

#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e3+5;
const int MOD = 1e4 + 7;
ll fact[N];
ll a, b, k , n, m;
void init_fact(){
    fact[0] = 1;
    for (int i = 1; i < N; ++i){
        fact[i] = fact[i-1] * i % MOD;
    }
}
ll qpow(ll a, ll b, ll p){
    ll res = 1;
    while(b){
        if (b & 1){
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll inv(ll a, ll p){
    return qpow(a, p-2, p);
}
ll C(ll n, ll m, ll p){
    if (m > n) return 0;
    return fact[n] % p * inv(fact[m], p) % p * inv(fact[n-m], p) % p;
}
int main(){
    init_fact();
    cin >> a >> b >> k >> n >> m;
    cout << C(k, n, MOD) % MOD * qpow(a, n, MOD) % MOD * qpow(b, m, MOD) % MOD;
}
```
### 埃式筛法
```cpp
#include <bits/stdc++.h>
using namespace std;

bitset<100000001> isprime;
int p[6000000];  // 1e8 内最多约 576万素数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    isprime.set();
    isprime[0] = isprime[1] = false;
    for (int i = 2; 1LL * i * i <= b; ++i) {
        if (isprime[i]) {
            for (long long j = 1LL * i * i; j <= b; j += i)
                isprime[j] = false;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= b; ++i)
        if (isprime[i])
            p[cnt++] = i;

    for (int i = 0; i < cnt; ++i){
        if (p[i] >= a){
            int tmp = p[i];
            int tmp2 = 0;
            while (tmp){
                tmp2 *= 10;
                tmp2 += tmp % 10;
                tmp /= 10;
            }
            if (tmp2 == p[i]){
                cout << p[i] << "\n";
            }
        }
    }
    return 0;
}

```
