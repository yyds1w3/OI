#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (char ch : s)
    {
        if (ch >= 'a' && ch <= 'z')
            cout << char(ch - 0x20);
        else
            cout << ch;
    }
}