#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, r;
    cin >> h >> r;
    double v = 3.14 * r * r * h;
    int n = ceil(20e3 / v);
    cout << n;
}