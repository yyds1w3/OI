#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        int sum = 0;
        int x;
        int not_zero_count = 0; // 非0元素
        for (int j = 1; j <= n; ++j){
            cin >> x;
            if (x != 0) not_zero_count++;
            sum += x;
        }
        cout << min(not_zero_count, sum - n + 1) << endl;
    }

}