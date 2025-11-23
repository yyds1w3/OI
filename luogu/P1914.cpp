#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (char ch : s)
    {
        ch = (ch - 'a' + n) % 26 + 'a';
        cout << ch;
    }
}