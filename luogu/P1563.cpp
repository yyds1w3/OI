#include <iostream>
using namespace std;

int n, m;
bool a[100001];
string s[100001];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> a[i] >> s[i];
    }
    int x,y,r=0;
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        (a[r] ^ x) ? r += y : r -= y; // 1 --> r += y 0 --> r -= y r [0,n-1]
        r = (r + n) % n;
    }

    cout << s[r];
}
