#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, a, b, sx, sy, ex, ey;
ll ans;
int main(){
    IOS
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i){
        cin >> sx >> sy >> ex >> ey;
        sx = max(sx, 0);
        sy = max(sy, 0);
        ex = min(ex, a);
        ey = min(ey, b);
        if (ey > sy && ex > sx)
        ans += (ey - sy) * (ex - sx);
    }
    cout << ans;
}