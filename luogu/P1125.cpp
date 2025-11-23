#include <bits/stdc++.h>
using namespace std;

int t[26];
bool is_prime(int x){
    if (x == 1 || x == 0) return false;
    if (x == 2 || x == 3) return true;
    bool ans = true;
    for (int i = 2; i * i <= x; ++i){
        if (x % i == 0){
            ans = false;
            break;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    int Minn = INT_MAX, Maxn = 0;    
    for (char c : s){
        t[c - 'a']++;
    }
    for (int i = 0; i < 26; ++i){
        Maxn = max(Maxn, t[i]);
        if (t[i] != 0) Minn = min(Minn, t[i]);
    }
    int ans = Maxn - Minn;
    if (is_prime(ans)){
        cout << "Lucky Word" << endl << ans;
    }else{
        cout << "No Answer" << endl << 0;
    }

}