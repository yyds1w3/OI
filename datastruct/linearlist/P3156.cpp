#include <iostream>
using namespace std;
int a[1000000001] = {0};
int main()
{
    int n, m, z;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> z;
        cout << a[z] << endl;
    }
}