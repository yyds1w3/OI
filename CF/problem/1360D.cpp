/*
 * 根号n找最大因子
*/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    IOS
    int t, n, k;
    cin >> t;
    for (int j = 1; j <= t; ++j){
        cin >> n >> k;
        int max_pkg = 1;
        for (int i = 1; i * i <= n; ++i){
            if (n % i == 0){
                if (i <= k){
                    max_pkg = max(max_pkg, i);
                }
                if (n / i <= k){
                    max_pkg = max(max_pkg, n / i);
                }
            }
        }
        cout << n / max_pkg << '\n';

    }
}