#include <bits/stdc++.h>

using namespace std;
int main()
{
    int T, N, k;
    cin >> T;
    for (int i = 0; i < T; ++i){
        cin >> N >> k;
        if (N >= (k + 1) * k / 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}