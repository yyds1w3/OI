#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> a[5001];

int main() {
    int n, m;
    long long ans = 0;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + m, [](pair<int,int> x, pair<int,int> y) {
        return x.first < y.first; 
    });

    for (int i = 0; i < m; ++i) {
        int x = min(n, a[i].second);
        n -= x;
        ans += 1LL * x * a[i].first;
        if (n == 0) break;
    }

    cout << ans << endl;
}
