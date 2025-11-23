#include <iostream>
#include <string>
#include <map>
using namespace std;
bool a[11][11];
int main()
{
    string s;
    map<string, bool> m;
    int N, M, ans = 0;
    cin >> N >> M;
    char c;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> c;
            c == '#' ? a[i][j] = 0 : a[i][j] = 1;
        }
    }
    for (int i = 1; i <= N - M + 1; ++i){
        for (int j = 1; j <= N - M + 1; ++j){
            for (int k = 0; k <= M - 1; ++k){
                for (int l = 0; l <= M - 1; ++l){
                    a[i + k][j + l] == 0 ? s += '0' : s += '1';
                }
            }
            if (m.find(s) == m.end()){
                m[s] = 1;
                ans++;
            }
            s.clear();
        }
    }
    cout << ans;
}