#include <bits/stdc++.h>
using namespace std;
#define f(i, n) for (int i = 0; i < n; ++i)
int main()
{
    int n, m, k, s;
    int maxn, minn;
    double ans = 0;
    cin >> n >> m;
    f(i, n){
        maxn = 0;
        minn = 11;
        s = 0;
        f(j, m){
            cin >> k;
            s += k;
            maxn = max(k, maxn);
            minn = min(k, minn);
        }
        s -= maxn + minn;
        ans = max(ans, s / double(m - 2));
    }
    cout << setprecision(2) << fixed << ans;
}