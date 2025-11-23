#include <bits/stdc++.h>
using namespace std;

int a[4];

int main()
{
    cin >> a[1] >> a[2] >> a[3];
    sort(a + 1, a + 4);
    cout << a[1] / gcd<int,int>(a[1], a[3]) << '/' << a[3] / gcd<int,int>(a[1], a[3]) << '\n';
    return 0;
    
}