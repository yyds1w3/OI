#include <bits/stdc++.h>
using namespace std;

int main()
{
    int y, m;
    cin >> y >> m;
    vector<int> BigMonth =  {1, 3, 5, 7, 8, 10, 12};
    vector<int> SmallMonth = {2, 4, 6, 7, 11};
    if (find(BigMonth.begin(), BigMonth.end(), m) != BigMonth.end())
        cout << 31;
    else if (m != 2)
        cout << 30;
    else 
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            cout << 29;
        else
            cout << 28;
}