#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
const int N = 4001;
ll ans = 0x3f3f3f3f;
ll a[3001], c[3001];
int main(){
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    for (int i = 2; i <= n - 1; ++i){
        ll min_cost_l = 0x3f3f3f3f;
        ll min_cost_r = 0x3f3f3f3f;
        for (int j = 1; j < i; ++j){
            if (a[j] < a[i]){
                min_cost_l = min(c[j], min_cost_l);
            }
        }
        for (int j = i + 1; j <= n; ++j){
            if (a[j] > a[i]){
                min_cost_r = min(c[j], min_cost_r);
            }
        }
        ans = min(ans, min_cost_r + min_cost_l + c[i]);
    }
    ans == 0x3f3f3f3f ? cout << "-1" : cout << ans;
}