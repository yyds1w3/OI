#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, neg = 0;
    cin >> N;
    vector<int> v;
    if (N < 0)
    {
        N *= -1;
        neg = 1;
    }
    if (N == 0)
    {
        cout << 0;
        return 0;
    }
    for (; N > 0; N /= 10)
    {
        v.emplace_back(N % 10); // 830 --> 0 3 8
    }
    if (neg)
        cout << "-";
    bool had_highest = 0;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (*it == 0 && !had_highest)
            continue;
        cout << *it;
    }
}