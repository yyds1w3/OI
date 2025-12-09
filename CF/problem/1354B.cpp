#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    string s;
    for (int i = 1; i <= t; ++i){
        cin >> s;
        int l = 0, r = 0;
        int cnt[4] = {0};
        int min_len = 0x3f3f3f3f;
        int s_len = s.length();
        for (; r < s_len; ++r){ // 主动权在r
            cnt[s[r] - '0']++;
            while (cnt[1] >= 1 && cnt[2] >= 1 && cnt[3] >= 1){ // 只要合法就一直收缩
                min_len = min(min_len, r - l + 1);
                cnt[s[l] - '0']--;
                l++;
            }
        }
        if (min_len == 0x3f3f3f3f) cout << 0 << '\n';
        else cout << min_len << '\n';

    }
}