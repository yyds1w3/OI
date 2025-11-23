#include <bits/stdc++.h>
using namespace std;


int wei(int x)
{
    int w = 0;
    if (x < 0)
        w = 1;
    while (x)
    {
        x /= 10;
        w++;
    }
    return w;
}
int main()
{
    char type;
    string s;
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        stringstream ss(s);
        int a, b;
        if (count(s.begin(), s.end(), ' ') == 2)
        {
            ss >> type >> a >> b;
        }else
        {
            ss >> a >> b;
        }
        switch (type)
        {
        case 'a':
            printf("%d+%d=%d\n%d\n", a, b, a + b, wei(a) + wei(b) + wei(a+b) + 2);
            break;
        case 'b':
            printf("%d-%d=%d\n%d\n", a, b, a - b, wei(a) + wei(b) + wei(a-b) + 2);
            break;
        case 'c':
            printf("%d*%d=%d\n%d\n", a, b, a * b, wei(a) + wei(b) + wei(a * b) + 2);
            break;
        default:
            break;
        }
    }
}
