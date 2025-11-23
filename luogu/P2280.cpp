#include <iostream>
#include <algorithm>
int a[5002][5002];

using namespace std;
int main(){
    int n, m, x, y, v;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> x >> y >> v;
        a[x+1][y+1] += v;
    }
    for (int i = 1; i < 5002; ++i){
        for (int j = 1; j < 5002; ++j){
                a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    for (int i = 5001; i >= m; --i){
        for (int j = 5001; j >= m; --j){
            ans = max(ans, a[i][j] - a[i-m][j] - a[i][j-m] + a[i-m][j-m]); // 右下角为a[i][j]的边长为m的正方形和a[i][j-m+1] + .... a[i][j],所以此处应该是m为界限而非m+1
        }
    }
    cout << ans;
}