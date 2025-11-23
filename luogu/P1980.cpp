#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    int x;
    cin >> n >> x;

    long long ans = 0;
    long long i = 1; // 当前处理的位权（1,10,100,...）

    while (i <= n)
    {
        long long high = n / (i * 10); // 高位部分
        long long cur = (n / i) % 10;  // 当前位
        long long low = n % i;         // 低位部分

        if (cur < x)
            ans += high * i;
        else if (cur == x)
            ans += high * i + low + 1;
        else
            ans += (high + 1) * i;

        if (x == 0)
            ans -= i; // 修正“0”不能出现在最高位的情况

        i *= 10;
    }

    cout << ans;
}
