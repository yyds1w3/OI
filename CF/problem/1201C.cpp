#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
ll a[N];
int n, k;
bool check(ll x){
    ll cost = 0;
    for (int i = n / 2 + 1; i <= n; ++i){
        cost += max(0LL, x - a[i]);
        if (cost > k) return false;
    }
    return cost <= k;
}
ll bsearch(){
    ll l = 0, r = 2e9;
    while (l < r){
        ll mid = (l + r + 1) >> 1;
        if (check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
}
int main(){
    IOS;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    cout << bsearch();
}