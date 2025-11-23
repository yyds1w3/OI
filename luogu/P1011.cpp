#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[30];
int main()
{
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    f[0] = a;f[1] = 0;
    while (1)
    {   
        for (int i = 2; i < n - 1 ; ++i){
            f[i] = f[i-1] + f[i-2];
        }
        if (f[n-2]-f[1] == m - a)
            break;
        f[1]++;
    }
    
    cout << f[x-1] - f[1] + f[0]; 
}