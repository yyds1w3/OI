#include <bits/stdc++.h>
using namespace std;


// 1. O(n)
// int main()
// {
//     int n, x;
//     cin >> n;
//     int last = -1, answer = 0, s = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> x;
//         if (last == -1)
//             last = x;
//         if (x - last == 1)
//             s++;
//         else
//         {
//             answer = max(answer, s);
//             s = 0;
//         }
//         last = x;
//     }
//     answer++;
//     cout << answer;
// }


// 2. 递归O(n^2)

// int n, a[10001] = {0}, maxn = 0;
// int f(int i)
// {
//     if (i == n - 1)
//         return 1;
//     if (a[i+1] == a[i] + 1)
//         return f(i + 1) + 1;
//     else
//         return 1;
// }
// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; ++i)
//         cin >> a[i];
//     for (int i = 0; i < n; ++i)
//         maxn = max(maxn, f(i));

//     cout << maxn;
// }

// 3. dp,O(n) 用空间换时间，逆序输出


int n, a[10001] = {0}, dp[10001] = {0}, maxn = 0;
int main()
{
    cin >> n;
    for (int i = 1; i < n+1; ++i)
    {
        cin >> a[i];
    }

    for (int i = n; i > 0; --i)
    {
        if (i == n)
            dp[i] = 1;
        else
        {
            if (a[i] == a[i+1] - 1)
            {
                dp[i] = dp[i + 1] + 1;
            }else
            {
                dp[i] = 1;
            }
        }
        maxn = max(maxn, dp[i]);
    }
    cout << maxn;
}