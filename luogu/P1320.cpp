#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, now = 0, times = 1;
    string s;
    getline(cin, s);
    N = s.length();
    cout << N << " ";
    int ans = 0;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if ((*it - '0') == now)
            ans++;
        else
        {
            cout << ans << " " << flush;
            now = 1 - now;
            ans = 1;
        }
    }
    while (getline(cin, s))
    {
        times++;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if ((*it - '0') == now)
                ans++;
            else
            {
                cout << ans << " " << flush;
                now = 1 - now;
                ans = 1;
            }
        }
        if (times == N)
        {
            cout << ans;
            break;
        }
    }
}