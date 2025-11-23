#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a = 0, b = 0;
    int thousand=0, hundred=0, ten =0, ge = 0;
    cin >> a;
    a *= 10;
    thousand = int(a / 1000); // 4
    hundred = (int)(a / 100) % 10; // 3
    ten = int(a / 10) % 10; // 2
    ge = int(a) % 10; // 1
    b = thousand * 0.001 + hundred * 0.01 + ten * 0.1 + ge * 1;
    cout << b;
}