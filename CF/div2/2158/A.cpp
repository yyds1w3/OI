#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, y, r;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n >> y >> r;
        cout << min(n, y / 2 + r) << "\n";
    }
}