#include <bits/stdc++.h>
using namespace std;

bool is_premier(int x)
{
    if (x == 0 || x == 1)
        return 0;
    bool ans = 1;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0){
            ans = 0;
            break;
        }
    }
    return ans;
}
int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (is_premier(x))
            cout << x << " ";
    }
}
