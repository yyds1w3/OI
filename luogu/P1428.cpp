#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a1[101] = {0}, a2[101] = {0};
    cin >> n;
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> a1[i];
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a1[i] > a1[j])
            {
                a2[i]++;
            }
        }
        cout << a2[i] << " ";
    }
}