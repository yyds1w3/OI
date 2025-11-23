#include <bits/stdc++.h>
using namespace std;
uint32_t x;
bool c1 = 0, c2 = 0;
bool opinions[4] = {0};
int main()
{
    cin >> x;
    if (x % 2 == 0)
        c1 = 1;
    if (x > 4 && x <= 12)
        c2 = 1;
    opinions[0] = c1 && c2;
    opinions[1] = c1 || c2;
    opinions[2] = (c1 && !c2) || (!c1 && c2);
    opinions[3] = !c1 && !c2;
    for (int i = 0; i < 4; ++i)
        cout << opinions[i] << " ";
}