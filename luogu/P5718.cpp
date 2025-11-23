#include <iostream>
#include <algorithm>
using namespace std;

/*
利用stl的sort
int main()
{
    int n, a[101] = {0};
    cin >> n;
    for (int i = 1; i < n + 1; ++i)
    cin >> a[i];
    sort(a + 1, a + 1 + n);
    cout << a[1];
}
*/
/*
利用桶排序（拿桶的序号作为值
*/
int main()
{
    int n, a, t[1001] = {0};
    cin >> n;
    for (int i = 1; i < n+1; ++i)
    {
        cin >> a;
        t[a]++;
    }
    for (int i = 1; i < 1001; ++i)
    {
        if (t[i] > 0)
        {
            cout << i;
            break;
        }
    }
}
