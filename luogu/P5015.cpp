#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int sum = 0;
    while (cin >> s)
    {
        sum += s.length();
    }
    cout << sum;
}
