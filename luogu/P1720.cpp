#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long F_n = 1, F_nm1 = 1, F_nm2 = 0; // 0 1 1 2 3
    cin >> n;
    if( n == 0)
        {
            cout << 0 << ".00" << endl;
            return 0;
        }
    else if (n == 1)
    {
        cout << 1 << ".00" << endl;
        return 0;
    }
    for (int i = 2; i < n + 1; i++)
    {
        F_n = F_nm1 + F_nm2;
        F_nm2 = F_nm1;
        F_nm1 = F_n;
    }
    cout << F_n << ".00" << endl;
}