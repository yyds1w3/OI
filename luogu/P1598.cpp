#include <bits/stdc++.h>
using namespace std;
int c[26][400] = {0};
int main()
{
    string s;
    int maxn = 0;
    int lm = 0;
    while (lm < 4)
    {
        getline(cin, s);
        for (int i = 0; i < int(s.length()); ++i)
        {
            if (!(s[i] >= 'A' && s[i] <= 'Z'))
                continue;
            maxn = max(maxn, ++(c[s[i] - 'A'][0]));
        }
        lm++;
    }
    int t = maxn;
    for (int i = 0; i < maxn; ++i)
    {
        for (int j = 0; j < 26; ++j){
            if (c[j][0] < t)
                cout << " ";
            else
                cout << "*";
            if (j != 25)
                cout << " ";
        }
        t--;
        cout << endl;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << char(i + 'A') << " ";
    }
}