#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
string s1, s2;
int pi[N];
void kmp(){
    int n = s1.length();
    int m = s2.length();

    s1 = ' ' + s1;
    s2 = ' ' + s2;
    for (int i = 2, j = 0; i <= m; ++i){
        while(j > 0 && s2[i] != s2[j+1]){
            j = pi[j];
        }
        if (s2[i] == s2[j + 1]){
            j++;
        }
        pi[i] = j;
    }
    for (int i = 1, j = 0; i <= n; ++i){
        while(j > 0 && s1[i] != s2[j+1]){
            j = pi[j];
        }
        if (s1[i] == s2[j + 1]){
            j++;
        }
        if (j == m){
            cout << i - m + 1 << '\n';
            j = pi[j];
        }
    }
    for (int i = 1; i <= m; ++i) cout << pi[i] << " ";

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s1 >> s2;
    kmp();
}