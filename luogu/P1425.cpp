#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = 0, f = 0;
    if (d >= b)
    {
        e = c - a;
        f = d - b;
    }else
    {
        e = c - a - 1;
        f = d - b + 60;
    }
    cout << e <<  " " << f;
}