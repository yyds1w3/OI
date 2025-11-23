#include <bits/stdc++.h>
using namespace std;
bool bo[11];

int main()
{
    for (int i = 123; i < 333; ++i){
        bo[i / 100] = 1;
        bo[i / 10 % 10] = 1;
        bo[i % 10] = 1;
        bo[2 * i / 100] = 1;
        bo[2 * i / 10 % 10] = 1;
        bo[2 * i % 10] = 1;
        bo[3 * i / 100] = 1;
        bo[3 * i / 10 % 10] = 1;
        bo[3 * i % 10] = 1;
        if (bo[1] && bo[2] && bo[3] && bo[4] && bo[5] && bo[6] && bo[7] && bo[8] && bo[9])
            cout << i << " " << 2 * i << " " << 3 * i << endl;
        memset(bo + 1, 0, 9);
    }
}