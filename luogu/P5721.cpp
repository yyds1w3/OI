#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int now = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = now; j <  now + n - i; ++j)
        {
            printf("%02d", j);
        }
        now += n - i;
        cout << endl;
    }
}
