#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
ll a[100001], b[100001];
int n;
ll k;
bool check(ll x){
    ll need = 0;
    for (int i = 1; i <= n; ++i){
        need += a[i] * x - min(a[i] * x, b[i]);
        if (need > k) return false;
    }
    return k >= need;
}
ll bsearch(){
    ll l = 0, r = 2e9;
    while (l < r){
        ll mid = (l + r + 1) / 2;
        if (check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    return l;
}
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    cout << bsearch();

}