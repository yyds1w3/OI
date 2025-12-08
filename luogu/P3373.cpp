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