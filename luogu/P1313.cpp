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