#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 101;
set<string> st1, st2;
vector<string> v1, v2;
int n, m;
string s;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        st1.insert(s);
    }
    for (int i = 1; i <= m; ++i){
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        st2.insert(s);
    }
    set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(), back_inserter(v1));
    set_union(st1.begin(), st1.end(), st2.begin(), st2.end(), back_inserter(v2));
    cout << v1.size() << "\n" << v2.size();
}
int main(){
    solve();
}
