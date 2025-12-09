/**
 * Algorthim: Hash
 * Verified: Luogu P3370
 * Complexity: Init O(N), Query O(1)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// =====================start==========================
struct StringHash{
    const ll P1 = 131, MOD1 = 1e9 + 7;
    const ll P2 = 13331, MOD2 = 1e7 + 7;

    vector<ll> h1, p1;
    vector<ll> h2, p2;

    void init(const string& s){
        int n = s.length();
        // h[i+1] = h[i] * P + s[i+1] % MOD
        h1.assign(n + 1, 0); p1.assign(n + 1, 0);
        h2.assign(n + 1, 0); p2.assign(n + 1, 0);

        for (int i = 0; i < n; ++i){
            p1[i + 1] = (p1[i] * P1) % MOD1;
            h1[i + 1] = (h1[i] * P1 + s[i + 1]) % MOD1;

            p2[i + 1] = (p2[i] * P2) % MOD2;
            h2[i + 1] = (h2[i] * P2 + s[i + 1]) % MOD2;
        }
    }
    pair<ll, ll> get(int l, int r){
        // 区间哈希公式: H[l...r] = H[r] - H[l-1] * P^(len)
        ll res1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % MOD1 + MOD1) % MOD1;
        ll res2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return {res1, res2};
    }
};

// ==========================End======================
int main(){
    IOS;
    int n;
    cin >> n;

    set<pair<ll, ll>> distinct_strings;
    StringHash hasher;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // 初始化计算哈希
        hasher.init(s);
        // 获取整个字符串的哈希值 (1 到 length)
        distinct_strings.insert(hasher.get(1, s.length()));
    }
    
    cout << distinct_strings.size() << "\n";
}