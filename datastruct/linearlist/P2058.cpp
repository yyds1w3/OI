
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <ios>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long country[100001];
int main()
{
    IOS;
    int n, ans = 0;
    int r;
    queue<map<int, set<int>>> q;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x, y, z;
        cin >> x >> y;
        static int l = x;
        r = x;
        map<int, set<int>> m;
        for (int j = 0; j < y; ++j){
            cin >> z;
            m[x].insert(z);
        }
        for (int c : m[x]){
            country[c]++;
            if (country[c] == 1){
                ans++;
            }
        }
        q.push(m);
        while (r - l >= 86400){
            for (int ll : q.front().begin()->second){
                country[ll]--;
                if (country[ll] == 0){
                    ans--;
                }
            }
            q.pop();
            l = q.front().begin()->first;
        }
        cout << ans << endl;
    }
}