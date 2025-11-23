#include <iostream>
using namespace std;

int main()
{
    int n, m, a[101] = {0}, live, now = 1, index = 1;
    cin >> n >> m;
    live = n;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = i;
    }
    while (live)
    {
        if (a[index] == 0)
        {
            index = (index % n) + 1;
            continue;
        }
        if (now == m)
        {
            live--;
            a[index] = 0;
            now = 1;
            cout << index << " ";
        }
        else
        {
            now++;
            index = (index % n) + 1;
        }
    }
}