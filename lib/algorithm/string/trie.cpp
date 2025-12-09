/**
 * Algorthim: Trie
 * Verified: Luogu P8306
 * Complexity: O(Len)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// =====================start==========================
const int MAXLEN = 3e6 + 5;
struct Trie{
    int son[MAXLEN][65]; // 0-9, a-z, A-Z
    int cnt[MAXLEN];
    int idx;

    void init(){
        idx = 0;
        memset(son[0], 0, sizeof(son[0]));
        cnt[0] = 0;
    }
    int get_id(char c){
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'z') return c - 'a' + 10;
        return c - 'A' + 36;
    }
    void insert(const string& s){
        int p = 0; // 我在son[p]
        for (char c : s){
            int u = get_id(c);
            if (!son[p][u]){ // 如果son[p][u]没有来过
                son[p][u] = ++idx; // son[p][u]的下一个房间是son[idx]
                memset(son[idx], 0, sizeof(son[idx]));
                cnt[idx] = 0;
            }
            p = son[p][u];
            cnt[p]++;
        }
    }
    int query(const string& s){
        int p = 0;
        for (char c : s){
            int u = get_id(c);
            if (!son[p][u]) return 0;
            p = son[p][u];
        }
        return cnt[p];
    }
}trie;

// ==========================End======================
int main(){
    IOS;
    int t, n, q;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        trie.init();
        cin >> n >> q;
        string s;
        for (int j = 1; j <= n; ++j){
            cin >> s;
            trie.insert(s);
        }
        for (int j = 1; j <= q; ++j){
            cin >> s;
            cout << trie.query(s) << '\n';
        }
    }
}