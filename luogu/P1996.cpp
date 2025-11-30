#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; // 稍微大一点
const int MOD = 1e8 - 3;
typedef long long ll;

struct Node {
    int value, id;
    // 【修正】标准写法最好加 const
    bool operator<(const Node &other) const {
        return value < other.value;
    }
} A[N], B[N];

ll ans;
int n;
int Tree[N];
int C[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int k) {
    // 【关键】x 不能为 0，否则死循环
    while(x <= n) {
        Tree[x] += k;
        x += lowbit(x);
    }
}

int ask(int x) {
    int sum = 0;
    while(x > 0) {
        sum += Tree[x];
        x -= lowbit(x);
    }
    return sum;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i].value; // 值
        A[i].id = i; // 本来的座位号
    }
    for (int i = 1; i <= n; ++i) {
        cin >> B[i].value;
        B[i].id = i;
    }
    // 值从小到大的数组, A[i].id代表他们应该的座位号
    sort(A + 1, A + 1 + n);
    sort(B + 1, B + 1 + n);
    // B中本来坐在B[i].id的人应该去A[i].id, 因为B和A排序过了, 所以B[i]和A[i]他们的排名是相对应的, 我们要让排名相对应的人去相对应的位置
    for (int i = 1; i <= n; ++i) {
        C[B[i].id] = A[i].id; // 当i==1,B中最小的人应该去A中最小的人的位置, 这就是C[i]的意义：在B中第i小的人应该去C[i]处的位置.这时候C[i]不再因为大小排序, 而是id->id
    }
    // 如果发现C[i] != i(不是从小到大), 其中C[i]意思是B的原来的位置, i是他应该去的位置(从小到大)， 我们要让C = {1,2,3,4,5}, 他们才不会动了
    for (int i = 1; i <= n; ++i) {
        add(C[i], 1);
        ans += i - ask(C[i]);
        ans %= MOD;
    }
    
    cout << ans << "\n";
}

int main() {
    solve();
}