#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n = 0;
    long long s = 0;
    int i = 0;
    while (cin >> n)
    {
        s += n;
        i++;
    }

    cout << s * pow(2, i - 1);
}