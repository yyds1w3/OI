#include <iostream>
using namespace std;
int main()
{
    int n, a[10001] = {0};
    cin >> n;
    int j = 10001;
    for (int i = 1; i < j; ++i)
    {
        a[i] = n;
        if (n == 1)
            j = i;
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
    }
    for (int k = j; k > 0; k--)
    {
        cout << a[k] << " ";
    }
}