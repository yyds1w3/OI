#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[101];
    int i = 1;
    while (cin)
    {
        cin >> a[i];
        ++i;
    }
    for (int j = i-3; j > 0; --j)
    {
        cout << a[j] << " ";
    }
}