#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
pair<ll, ll> pi[N];
int n;
ll sx, sy, ex, ey;

bool check(ll x){
    ll cnt = x / n;
    ll rem = x % n;
    ll need = abs(cnt * pi[n].first + pi[rem].first + sx - ex)
    + abs(cnt * pi[n].second + pi[rem].second + sy - ey);
    return x >= need;
}
ll bsearch(){
    ll l = 0, r = 2e14 + 1;
    while (l < r){
        ll mid = (l + r) >> 1;
        if (check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return l;
}
int main(){
    IOS;
    string s;
    cin >> sx >> sy >> ex >> ey;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i){
        pi[i] = pi[i-1];
        switch (s[i-1]){
        case 'U':
            pi[i].second++;break;
        case 'D':
            pi[i].second--;break;
        case 'L':
            pi[i].first--;break;
        case 'R':
            pi[i].first++;break;
        default:
            break;
        }
    }
    ll ans = bsearch();
    if (ans == 2e14 + 1) cout << "-1";
    else cout << ans;
}