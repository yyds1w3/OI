/**
 * Algorithm: Combinatorics (nCr, nPr)
 * Verified: Luogu P3811 (Converted to Linear Inverse)
 * Complexity: Init O(N), Query O(1)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e6 + 5; 

struct Comb {
    ll fact[MAXN], invFact[MAXN];
    ll MOD;

    ll qpow(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    void init(int n, int mod) {
        MOD = mod;
        fact[0] = 1;
        invFact[0] = 1;
        
        // 1. 预处理阶乘
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        
        // 2. 费马小定理求最大阶乘的逆元
        invFact[n] = qpow(fact[n], MOD - 2); 
        
        // 3. 倒推求所有阶乘逆元
        for (int i = n - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    // 计算 C(n, m)
    ll C(int n, int m) {
        if (m < 0 || m > n) return 0;
        return fact[n] * invFact[m] % MOD * invFact[n - m] % MOD;
    }

    // 计算 A(n, m)
    ll A(int n, int m) {
        if (m < 0 || m > n) return 0;
        return fact[n] * invFact[n - m] % MOD;
    }

    ll getInv(int i) {
        if (i == 0) return 0; // 0没有逆元
        return invFact[i] * fact[i-1] % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    Comb comb;
    int n, p;
    cin >> n >> p;
    
    // 初始化到 n 即可
    comb.init(n, p);
    
    for (int i = 1; i <= n; ++i) {
        // 输出 i 的逆元，而不是 i! 的逆元
        cout << comb.getInv(i) << '\n';
    }
    
    return 0;
}