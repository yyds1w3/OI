#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s, v, m, h, sum;
    cin >> s >> v;
    sum = 10 + s / v + (s % v != 0);
    h = (32 - sum / 60 - (sum % 60 != 0)) % 24;
    m = (60 - sum % 60) % 60;
    printf("%02d:%02d", h, m);
}