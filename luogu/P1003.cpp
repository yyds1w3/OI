#include <bits/stdc++.h>
using namespace std;

int a[100001], b[100001], g[100001], k[100001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n ; ++i){
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    int x,y,ans;
    cin >> x >> y;
    for (int i = 1; i<= n; ++i){
        if (x >= a[i] && x < a[i]+g[i] && y >= b[i] && y < b[i] + k[i]){
            ans = i;
        }
    }
    cout << ans;
}