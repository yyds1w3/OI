int a[101][101];
int b[101][101];
#include <iostream>
int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        int v;
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> v;
            a[i][j] = v;
            b[i][j] = v;
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j){
            b[i][j] = a[i][j] + b[i][j - 1] + b[i - 1][j] - b[i-1][j-1];
            int MaxEdge = i < j ? i : j;
            while(MaxEdge >= 2){
                if (b[i][j] - b[i - MaxEdge][j] - b[i][j - MaxEdge] + b[i - MaxEdge][j - MaxEdge] == MaxEdge * MaxEdge){
                    ans = ans > MaxEdge ? ans : MaxEdge;
                    break;
                }
                MaxEdge--;
            }
        }
    }
    // for (int i = 1; i <= n; ++i){
    //     for (int j = 1; j <= m; ++j){
    //         std::cout << b[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << ans;
}