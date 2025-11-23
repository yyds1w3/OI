#include <bits/stdc++.h>
using namespace std;

bitset<100000001> isprime;
int p[6000000];  // 1e8 内最多约 576万素数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    isprime.set();
    isprime[0] = isprime[1] = false;
    for (int i = 2; 1LL * i * i <= b; ++i) {
        if (isprime[i]) {
            for (long long j = 1LL * i * i; j <= b; j += i)
                isprime[j] = false;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= b; ++i)
        if (isprime[i])
            p[cnt++] = i;

    for (int i = 0; i < cnt; ++i){
        if (p[i] >= a){
            int tmp = p[i];
            int tmp2 = 0;
            while (tmp){
                tmp2 *= 10;
                tmp2 += tmp % 10;
                tmp /= 10;
            }
            if (tmp2 == p[i]){
                cout << p[i] << "\n";
            }
        }
    }
    return 0;
}
