#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int n, k, s_a = 0, a_n = 0, s_b = 0, b_n = 0;
    cin >> n >> k;
    for (int i = 1; i < n + 1; i++)
    {
        if (i % k == 0)
        {
            s_a += i;
            a_n++;
        }
    }
    s_b = (n + 1) * n / 2 - s_a;
    b_n = n - a_n;
    cout << setprecision(1) << fixed << s_a / 1.0 / a_n << " " << s_b / 1.0 / b_n;
}
