/**
 * Algorithm: Inverse
 * Verified: Luogu P3811
 * Complexity:  - Single_inv: O(log MOD) using ExGCD
 *              - liner_inv: O(N)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);
// ========================start==========================

struct Inverse{
    vector<ll> inv;
    ll exgcd(ll a, ll b, ll &x, ll &y){
        if (b == 0){
            x = 1;
            y = 0;
            return a;
        }
        ll d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
    ll get_single_inv(ll a, ll m){
        ll x, y;
        exgcd(a, m, x, y);
        x = (x % m + m) % m;
        return x;
    }
    void init_linear(int n, int p){
        inv.assign(n + 1, 0);
        inv[1] = 1;
        for (int i = 2; i <= n; ++i){
            inv[i] = (ll)(p - p / i) * inv[p % i] % p;
        }   
        
    }
}inverse;

// ==========================End=========================
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, p;
    cin >> n >> p;
    // 1. 线性求法 (推荐，O(N) 极快)
    inverse.init_linear(n, p);
    for (int i = 1; i <= n; i++) {
        cout << inverse.inv[i] << "\n";
    }

    // 2. 如果只是单次查询，可以用 ExGCD
    // for (int i = 1; i <= n; ++i){
    //     cout << inverse.get_single_inv(i, p) << "\n";
    // }
    

}