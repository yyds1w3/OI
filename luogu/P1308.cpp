#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    s1 = ' ' + s1 + ' ';
    s2 = ' ' + s2 + ' ';
    for (auto it = s1.begin(); it != s1.end(); ++it)
        *it = toupper(*it);
    for (auto it = s2.begin(); it != s2.end(); ++it)
        *it = toupper(*it);
    int pos = s2.find(s1);
    int t = pos;
    if (pos == -1){
        cout << -1;
        return 0;
    }
    int cnt = 0;
    while (pos != -1)
    {
        cnt++;
        pos = s2.find(s1, pos + 1);
    }
    cout << cnt << ' ' << t;
}
