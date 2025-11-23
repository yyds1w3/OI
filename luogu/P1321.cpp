#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n1 = 0, n2 = 0, i1 = 0, i2 = 0;
    cin >> s;
    s+="......";

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'b' || s[i + 1] == 'o' || s[i+2] == 'y')
            n1++;
        if (s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l')
            n2++;
    }
    cout << n1 << " " << n2;
}