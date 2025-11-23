#include <iostream>
using namespace std;

int a[501][501];
int b[501][501];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            a[i][j] = n * (i - 1) + j;
            b[i][j] = n * (i - 1) + j;
        }
    }
    int x, y, r, z;
    for (int k = 1; k <= m; ++k){
        cin >> x >> y >> r >> z;
        int len = 2*r + 1; // 子矩阵边长
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < len; ++j){
                if(z == 0) // 顺时针
                    a[x-r + j][y-r + len-1 - i] = b[x-r + i][y-r + j];
                else // 逆时针
                    a[x-r + len-1 - j][y-r + i] = b[x-r + i][y-r + j];
            }
        }
        // 更新 b
        for(int i = 0; i < len; ++i)
            for(int j = 0; j < len; ++j)
                b[x-r + i][y-r + j] = a[x-r + i][y-r + j];
        }
            for (int i = 1; i <= n; ++i){
                for (int j = 1; j <= n; ++j){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
}
