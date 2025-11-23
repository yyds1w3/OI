#include <bits/stdc++.h>
using namespace std;
int a[400 * 400] = {0};
int main()
{
    int N;
    cin >> N;
    int now = 0, index = 0, ch;
    while (index < N * N){
        cin >> ch;
        for (int i = 1; i <= ch; ++i)
        {
            index++;
            cout << now;
            if (index % N == 0)
                cout << endl;
        }
        now = 1 - now;
    }
}