// #include <iostream>
// #include <cstring>
// using namespace std;
// int a[10001];
// int used[10001];
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> a[i];
//         int x = a[i];
//         for (int j = 1; j <= x; ++j)
//         {
//             if (used[j])
//             {
//                 a[i]--;
//             }
//         }
//         a[i]--;
//         used[x] = 1;
//     }
//     a[n] += m;
//     for (int i = n; i >= 2; --i)
//     {
//         if (a[i] >= n - i + 1)
//         {
//             a[i - 1] += a[i] / (n - i + 1);
//             a[i] %= (n - i + 1);
//         }
//     }
//     memset(used, 0, sizeof(used));
//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 0; j <= a[i]; ++j)
//         {
//             if (used[j])
//                 a[i]++;
//         }
//         used[a[i]] = 1;
//     }
//     for (int i = 1; i <= n; ++i)
//     {
//         cout << a[i] + 1 << " ";
//     }
// }

#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i){
        next_permutation(a, a+n);
    }
    for (int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
}