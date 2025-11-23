#include <bits/stdc++.h>
using namespace std;
int main()
{

    double s = 0, p = 0, a ,b, c;
    cin >> a >> b >> c;
    p = (a + b + c) / 2.0;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << setprecision(1) << fixed << s << endl;

}