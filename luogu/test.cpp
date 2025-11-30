#include <vector>
#include <iostream>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
typedef long long ll;
bool is_prime[N];
ll fact[N];
vector<int> primes;

/*
原理: 任意一个数i 他的(i*1 ~ n)一定不是质数, 又因为(1 * i ,2 * i )会被之前的1, 2给筛掉，所以从(i*i~n)开始
*/
void sieve(int n){
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++){
        if (is_prime[i]){
            primes.push_back(i);
            for (ll j = ll(i * i); j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
}

void euler_sieve(int n){
    fill(is_prime, is_prime + n + 1, true); // [0, n]
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i){
        if (is_prime[i]){
            primes.push_back(i);
        }
        // 这里与sieve不同
        // sieve是通过(i*i ~ n)
        // euler_sieve是因为一个合数只要被最小质因子标记一次
        // i 是半成品, primes[j]是零件, i 不能包括primes[j]
        for (int j = 0; j < primes.size(); ++j){ // primes里存的从小到大的质因子
            if (1LL * i * primes[j] > n) break;
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) break; // 精髓: 如果没break, 下一个X = i * primes[j]他的最小质因子应该在i里面而不是primes[j] 假设i == 4 primes[j] == 2 不停止就会 4 * 3 = 12 , 但是12应该是6 * 2 来筛
        }
    }
}

ll qpow(ll a, ll b, ll p){
    ll res = 1;
    a %= p;
    while (b){
        if (b & 1){
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

ll inv(ll n, ll p){
    return qpow(n, p-2, p);
}

void init_fact(){
    fact[0] = 1;
    for (int i = 1; i < N; ++i){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

ll C(ll n, ll m, ll p){ 
    if (m > n) return 0;
    return fact[n] % p * inv(fact[m], p) % p * inv(fact[n-m], p) % p;
}
int main() {
    // 1. 先初始化阶乘表（别忘了！）
    init_fact();
    
    // 2. 测试组合数
    int n, m;
    while (cin >> n >> m) {
        cout << C(n, m, MOD) << endl;
    }
    return 0;
}