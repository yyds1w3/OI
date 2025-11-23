#include <bits/stdc++.h>
using namespace std;

double calc_len(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main()
{
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << setprecision(2) << fixed << calc_len(x1, y1, x2, y2) + calc_len(x1, y1, x3, y3) + calc_len(x2, y2, x3, y3);
}
