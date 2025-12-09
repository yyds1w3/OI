/**
 * Algorthim: Extended Euclidean Algorithm(ExGCD) 
 * Verified: Luogu P1082
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// =================start=========================
struct Math{
    ll exgcd(ll a, ll b, ll &x, ll &y) {
        if (b == 0) {
            x = 1; 
            y = 0;
            return a;
        }
        ll d = exgcd(b, a % b, y, x); // x'在本层的y, y'在本层的x
        y -= a / b * x; // 回溯更新
        return d;
    }
    ll modInverse(ll a, ll b) { // ax = 1(mod b)
        ll x, y;
        ll d = exgcd(a, b, x, y);
        if (d != 1) return -1; // 如果gcd(a,b)!=1 ==>[ab不互质]==>[gcd永远不能==1]
        return (x % b + b) % b;
    }
}math;
// ===================end==============================
int main(){
    IOS;
    ll a, b;
    cin >> a >> b;
    ll ans = math.modInverse(a, b);
    cout << ans << "\n";
    return 0;
}
