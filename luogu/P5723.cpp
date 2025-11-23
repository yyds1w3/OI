#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(2);
    for (int i = 3; i < 100000; ++i)
    {
        bool strange = true;
        for (int j = 2; j < sqrt(i) + 1; ++j)
        {
            if (i % j == 0)
            {
                strange = false; // 不是质数
                break;
            }
        }
        if (strange == true)
            v.push_back(i);
    }
    int sum = 0, num = 0;
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        sum += *i;
        if (sum <= n)
        {
            cout << *i << endl;
            num++;
        }
    }
    cout << num;
}
