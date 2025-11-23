#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, n1, c1, n2, c2, n3, c3;
    array<int,3>sum = {0};
    cin >> n >> n1 >> c1 >> n2 >> c2 >> n3 >> c3;
    sum[0] = int(ceil(n / double(n1)) * c1);
    sum[1] = int(ceil(n / double(n2)) * c2);
    sum[2] = int(ceil(n / double(n3)) * c3);
    sort(sum.begin(), sum.end());
    cout << sum[0];
}