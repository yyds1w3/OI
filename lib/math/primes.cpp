/**
 * Algorithm: Linear Sieve (Euler Sieve)
 * Verified: Luogu P3383
 * Complexity: O(N)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// ========================start==========================
const int MAXN = 1e8 + 5;
const int MAX_PRIMES = 6e6 + 5; 

struct Sieve {
    int primes[MAX_PRIMES];
    bool not_primes[MAXN];  
    int cnt;

    void init(int n) {
        cnt = 0;
        not_primes[0] = not_primes[1] = true; 

        for (int i = 2; i <= n; ++i) {
            if (!not_primes[i]) {
                primes[cnt++] = i;
            }
            for (int j = 0; j < cnt; ++j) { // 在发现的质数里找最小的质因子
                if (1LL * i * primes[j] > n) break;
                not_primes[i * primes[j]] = true; // 标记合数
                if (i % primes[j] == 0) break; // 交给后面的数来筛
            }
        }
    }
} sieve; // 定义全局变量，防止栈溢出
// ======================End================================

int main() {
    IOS;
    int n, q;
    cin >> n >> q;
    sieve.init(n);
    
    while (q--) {
        int k;
        cin >> k;
        cout << sieve.primes[k - 1] << "\n";
    }
    return 0;
}