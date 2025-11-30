#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int triangle[N][N];
int main(){
    int r;
    cin >> r;
    for (int i = 1; i <= r; ++i){
        for (int j = 1; j <= i; ++j){
            cin >> triangle[i][j];
        }
    }
    // int ans = 0;
    // for (int i = 1; i <= r; ++i){
    //     for (int j = 1; j <= i; ++j){
    //         triangle[i][j] = triangle[i][j] + max(triangle[i-1][j], triangle[i-1][j-1]);
    //         ans = max([i][j], ans);
    //     }
    // }
    // cout << ans;
    for (int i = r - 1; i >= 1; --i){
        for (int j = 1; j <= i; ++j){
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    cout << triangle[1][1];
}