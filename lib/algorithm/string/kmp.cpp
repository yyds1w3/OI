/**
 * Algorthim: KMP (0-based)
 * Verified: Luogu P3375
 * Complexity: O(N + M)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// =============start===============
struct KMP{
    vector<int> pi;
    string P;

    void init(string &p){
        P = p;
        int m = P.length();
        pi.assign(m, 0);
        // i 指向后缀末尾
        // j 指向前缀末尾(已匹配长度)
        for (int i = 1, j = 0; i < m; ++i){
            while (j > 0 && P[i] != P[j]) j = pi[j-1];
            if (P[i] == P[j]) j++;
            pi[i] = j;
        }
    }
    vector<int> match(string& s) {
        int n = s.length();
        int m = P.length();
        vector<int> pos;
        
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && s[i] != P[j]) j = pi[j - 1];
            if (s[i] == P[j]) j++;
            if (j == m) {
                pos.push_back(i - m + 1);  // m 是长度
                j = pi[j - 1];
            }
        }
        return pos;
    }
};

// ===============End==================
int main(){
    IOS;
    string s1, s2;
    cin >> s1 >> s2;
    KMP kmp;
    kmp.init(s2);
    for (int p : kmp.match(s1)){
        cout << p+1 << '\n';
    }
    for (int p : kmp.pi){
        cout << p << ' ';
    }
}