#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, x, k = 0;
    cin >> N;
    int sum = N / 364;
    do
    {
        x = sum - 3 * k;
        if (x > 0 && x <= 100)
            break;
        k++;
    } while (k);

    cout << x << endl << k;
}