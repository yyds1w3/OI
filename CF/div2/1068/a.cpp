#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main(){
    IOS
    int t, n, k;
    string s;
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> n >> k >> s;
        int ans = 0;
        int awake = -1;
        for (int j = 0; j < n; ++j){
            if (s[j] == '1'){
                awake = j + k;
            }else{
                if (j > awake && s[j] == '0'){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}