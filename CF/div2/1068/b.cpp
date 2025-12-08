#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll INF = 1e18;
ll a[N], b[N], t;
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    ll mx = 0;
    ll mn = 0;
    for (int i = 0; i < n; ++i){ // 要让最终结果最大, 必须拿最大值和最小值
        ll cand1 = mx - a[i]; // 可能最大
        ll cand2 = b[i] - mx; // 可能最小
        ll cand3 = mn - a[i]; // 可能最小
        ll cand4 = b[i] - mn; // 可能最大
        mx = max({cand1, cand2, cand3, cand4});
        mn = min({cand1, cand2, cand3, cand4});
    }
    cout << mx << '\n';
}
int main(){
    IOS
    cin >> t;
    for (int i = 0; i < t; ++i){
        solve();
    }
}