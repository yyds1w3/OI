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