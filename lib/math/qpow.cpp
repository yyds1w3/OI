/**
 * Algorithm: Quick Pow
 * Verified: Luogu P1226
 * Complexity: O(log b)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// =================start=============================
struct Math{
    ll qpow(ll a, ll b, ll p){
        ll res = 1;
        a %= p;
        while (b){
            if (b & 1) res = (res * a) % p;
            a = (a * a) % p;
            b >>= 1;
        }
        return res;
    }
};
// ==================End=================================
int main() {
    IOS;
    ll a, b, p;
    cin >> a >> b >> p;
    Math math;
    cout << a << "^" << b << " mod " << p << "=" << math.qpow(a, b, p) << "\n";
}