#include <iostream>
using namespace std;
int main()
{
    bool cube[21][21][21] = {false};
    int w, x, h, q, x1, y1, z1, x2, y2, z2;
    cin >> w >> x >> h >> q;
    for (int i = 1; i < q + 1; ++i)
    {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; ++j)
                for (int k = z1; k <= z2; ++k)
                    cube[i][j][k] = 1;
    }
    int ans = w * x * h;
    for (int i = 1; i <= w; i++)
        for (int j = 1; j <= x; ++j)
            for (int k = 1; k <= h; ++k)
                if (cube[i][j][k] == 1)
                    ans -= 1;
    cout << ans;
}