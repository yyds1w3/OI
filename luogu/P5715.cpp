#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l[3];
    cin >> l[0] >> l[1] >> l[2];
    if (l[0] > l[1])
        swap<int>(l[0], l[1]);
    if (l[1] > l[2])
        swap<int>(l[1], l[2]);
    if (l[0] > l[1])
        swap<int>(l[0], l[1]);
    cout << l[0] << " " << l[1] << " " << l[2];
}