#include <bits/stdc++.h>
using namespace std;

int main()
{
    array<int,3> l;
    array<char,3> ll;
    cin >> l[0] >> l[1] >> l[2];
    sort(l.begin(), l.end());
    int a, b, c;
    a = l.at(0);
    b = l.at(1);
    c = l.at(2);
    cin >> ll[0] >> ll[1] >> ll[2];
    for (auto it = ll.begin(); it != ll.end(); ++it)
    {
        if (*it == 'A')
            cout << l[0] << " ";
        else if(*it == 'B')
            cout << l[1] << " ";
        else if(*it == 'C')
            cout << l[2] << " ";
    }
}