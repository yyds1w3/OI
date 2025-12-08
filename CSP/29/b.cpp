#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, m, k;
int max_t;
int t[N];
int c[N];
bool check(int x){
    ll ans = 0;
    for (int i = 1; i <= n; ++i){
        if (t[i] > x)
        ans += (ll)c[i] * (t[i] - x);
    }
    if (ans <= m) return true;
    return false;
}
int bsearch(){
    int l = k, r = max_t; 
    while (l < r){
        int mid = l + ((r - l) >> 1);
        if (check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return r;
}
void solve(){
    IOS
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        cin >> t[i] >> c[i];
        max_t = max(max_t, t[i]);
    }
    cout << bsearch();
}
int main(){
    solve();    
}