#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, q;
    int a, b, c, d;
    map<long long, int> m;
    cin >> n >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a >> b >> c ;
        if (a == 1)
        {
            cin >> d;
            m[b * 100000 + c] = d;
        }
        else if (a == 2)
        {
            cout << m[b * 100000 + c] << endl;
        }
    }
}