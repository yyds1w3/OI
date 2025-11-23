#include <bits/stdc++.h>
using namespace std;

int a[1005][1005];

int main() {
    int n, m;
    cin >> n >> m;

    int x1, y1, x2, y2;
    while (m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        a[x1][y1] += 1;
        a[x1][y2+1] -= 1;
        a[x2+1][y1] -= 1;
        a[x2+1][y2+1] += 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = a[i][j]
                    + a[i-1][j]
                    + a[i][j-1]
                    - a[i-1][j-1];

            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
