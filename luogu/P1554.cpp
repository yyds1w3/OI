#include <iostream>
using namespace std;
int main()
{
    int M, N, ans[10] = {0};
    static int a[500001][10];
    cin >> M >> N;
    for (int i = 0; i + M < N + 1; ++i)
    {
        int wei = 0;
        int Now = M + i;
        while (Now)
        {
            a[i][wei] = Now % 10; // 最后一位
            Now /= 10;            // 右移一位
            wei++;
        }
        for (int j = 0; j < wei; ++j)
        {
            ans[a[i][j]]++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << ans[i] << " ";
    }
}