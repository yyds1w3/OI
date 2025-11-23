#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, sum = 0;
    cin >> k;
    int gold = 1, continue_day = 0;
    for (int i = 1; i < k; ++i)
    {
        if (continue_day < gold)
            continue_day++;
        else{
            continue_day = 1;
            gold++;
        }
        sum += gold;
    }
}
