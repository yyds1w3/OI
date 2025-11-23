#include <bits/stdc++.h>
using namespace std;
#define f(i, n) for (int i = 0; i < n; ++i)
int arr[(1 << 10) + 1][(1 << 10) + 1] = {0};
int main()
{
    int n;
    cin >> n;
    int k = pow(2,n); // k = 8
    f(g, n){ // g in [0, 2] , n = 3
        for (int i = 1; i <= k-1; i += pow(2, g+1)){ // i in [1,3,5,7], [1, 5]
            for (int j = 1; j <= k - 1; j += pow(2, g + 1)){ // 左上角坐标 j in [1, 3, 5, 7], [1, 5]
                for (int m = 0; m < pow(2,g); ++m){ // m in [0], [0, 1, 2, 3]
                    for (int l = 0; l < pow(2,g); ++l) // l in [0]
                        arr[i + m][j + l] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            cout <<  1- arr[i][j] << " ";
        }
        cout << endl;
    }
}